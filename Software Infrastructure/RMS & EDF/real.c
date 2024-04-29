#include <stdio.h>
#include <stdlib.h>

#ifdef EDF
#define ALGORITHM 'E'
#elif RATE
#define ALGORITHM 'R'
#else
#define ALGORITHM 'D'
#endif

char alg = ALGORITHM;

typedef struct Task {
    char name[100];
    int t; // period
    int c; // cpu burst
    int run; // executed time
    int done; // boolean completed
    int unit; // saves the units ran
    int deadline;
    int lost_deadline; // outputs
    int completed;
    int killed;
} Task;

void rate(struct Task task[], int numberOfTasks, int totalTime);
void edf(struct Task task[], int numberOfTasks, int totalTime);
void bubbleSort(Task *arr, int n, int *original_indices);
Task* readTasksFromFile(char *filename, int *totalTime, int *numberOfTasks);

int main(int argc, char *argv[]) {
    int numberOfTasks;
    int totalTime;

    Task *unsorted_task = readTasksFromFile(argv[1], &totalTime, &numberOfTasks);


    if (alg == 'R') {
      rate(unsorted_task, numberOfTasks, totalTime);
    }
    else if (alg == 'E') {
      edf(unsorted_task, numberOfTasks, totalTime);
    }

    return 0;
}

void rate(struct Task unsorted_task[], int numberOfTasks, int totalTime) {
  int currentTime = 0;
  int totalIdle = 0;

  Task *task = (Task *)malloc(numberOfTasks * sizeof(Task));

  for (int i = 0; i < numberOfTasks; i++) {
      task[i] = unsorted_task[i];
  }

  int *original_indices = (int *)malloc(numberOfTasks * sizeof(int));
  if (original_indices == NULL) {
      free(unsorted_task);
      free(task);
  }
  for (int i = 0; i < numberOfTasks; i++) {
      original_indices[i] = i;
  }

  bubbleSort(task, numberOfTasks, original_indices);

  FILE *output = fopen("rate.out", "w");

  fprintf(output, "EXECUTION BY RATE\n");
  while (currentTime < totalTime) {
      int taskExecuted = 0;
      //printf("tempo: %d\n", currentTime);

      int all_done = 1;
      for (int i = 0; i < numberOfTasks; i++) {
          if (currentTime % task[i].t == 0) { // resets task when period is over
              task[i].done = 0;
              task[i].run = 0;
              task[i].killed++;
          }

          if (task[i].done == 0) {
              all_done = 0;
          }
      }

      if (all_done) {
          totalIdle ++;
      } else {
          if (totalIdle > 0) {
              fprintf(output, "idle for %d units\n", totalIdle);
              totalIdle = 0;
          }
      }

      // run first task
      if (currentTime % task[0].t == 0 && currentTime != totalTime) {
          while (task[0].run < task[0].c) {
              //printf("running %s. time: %d\n", task[0].name, currentTime);
              task[0].run++;
              currentTime++;
              if ((currentTime) == totalTime) {
                  taskExecuted = 1;
                  fprintf(output, "[%s] for %d units - %c\n", task[0].name, task[0].run, 'K');
                  task[0].killed++;
                  break;
              }
          }
          task[0].done = 1;
          task[0].killed--;
          if (currentTime != totalTime) {
              taskExecuted = 1;
              fprintf(output, "[%s] for %d units - %c\n", task[0].name, task[0].run, 'F');
              task[0].completed++;
          }
      }

      // run other task by priority
      if (currentTime % task[0].t != 0 && currentTime != totalTime) {
          for (int i = 1; i < numberOfTasks; i++) {
              task[i].unit = 0;
              if (task[i].done == 0 && currentTime % task[0].t != 0 && currentTime != totalTime) {
                  while (task[i].run < task[i].c) {
                      //printf("running %s. time: %d\n", task[i].name, currentTime);
                      task[i].run++;
                      task[i].unit++;
                      currentTime++;

                      if ((currentTime) % task[i].t == 0 && currentTime != totalTime) { // resets task when period is over
                          if (task[i].done == 0) {
                              taskExecuted = 1;
                              fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].unit, 'L');
                              task[i].lost_deadline++;
                              break;
                          }
                          task[i].done = 0;
                          task[i].killed--;
                          task[i].run = 0;
                      }

                      if ((currentTime) == totalTime) {
                          taskExecuted = 1;
                          fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].run, 'K');
                          task[i].killed++;
                          break;
                      }

                      int flag = 0; // puts on hold if task w biggest priority comes in
                      for (int j = 0; j < numberOfTasks; j++) {
                          if (task[i].run != task[i].c) {
                              if (currentTime % task[j].t == 0 && currentTime != totalTime) {
                                  flag = 1;
                                  taskExecuted = 1;
                                  fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].unit, 'H');
                                  break;
                              }
                          }
                      }
                      if (flag) {
                          break;
                      }

                  }

                  if (task[i].run == task[i].c) { // checks if task is finished
                      task[i].done = 1;
                      task[i].killed--;
                      taskExecuted = 1;
                      fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].unit, 'F');
                      task[i].completed++;
                  }
              }
          }
      }
      if (!taskExecuted) { // only increments here if idle
          currentTime++;
      }
  }

  if (totalIdle > 0) {
      fprintf(output, "idle for %d units\n", totalIdle);
  }

  Task *original_order_task = (Task *)malloc(numberOfTasks * sizeof(Task));
  if (original_order_task == NULL) {
      free(unsorted_task);
      free(task);
      free(original_indices);
  }
  for (int i = 0; i < numberOfTasks; i++) {
      original_order_task[original_indices[i]] = task[i];
  }

  fprintf(output, "\nLOST DEADLINES\n");
  for (int i = 0; i < numberOfTasks; i++) {
    fprintf(output, "[%s] %d\n", original_order_task[i].name, original_order_task[i].lost_deadline);
  }

  fprintf(output, "\nCOMPLETE EXECUTION\n");
  for (int i = 0; i < numberOfTasks; i++) {
    fprintf(output, "[%s] %d\n", original_order_task[i].name, original_order_task[i].completed);
  }

  fprintf(output, "\nKILLED\n");
  for (int i = 0; i < numberOfTasks; i++) {
      if (i != (numberOfTasks - 1)) {
          fprintf(output, "[%s] %d\n", original_order_task[i].name, original_order_task[i].killed);
      }
      else {
          fprintf(output, "[%s] %d", original_order_task[i].name, original_order_task[i].killed);
      }
  }
  free(unsorted_task);
  free(task);
  free(original_indices);
  fclose(output);
}

void edf(struct Task unsorted_task[], int numberOfTasks, int totalTime) {
    int currentTime = 0;
    int totalIdle = 0;

    Task *task = (Task *)malloc(numberOfTasks * sizeof(Task));

    for (int i = 0; i < numberOfTasks; i++) {
        task[i] = unsorted_task[i];
    }

    int *original_indices = (int *)malloc(numberOfTasks * sizeof(int));
    if (original_indices == NULL) {
        free(unsorted_task);
        free(task);
    }
    for (int i = 0; i < numberOfTasks; i++) {
        original_indices[i] = i;
    }

    bubbleSort(task, numberOfTasks, original_indices);

    FILE *output = fopen("edf.out", "w");

    for (int i = 0; i < numberOfTasks; i++) {
        task[i].deadline = task[i].t; // deadline == period
    }

    fprintf(output, "EXECUTION BY EDF\n");
    while (currentTime < totalTime) {
        int taskExecuted = 0;
        //printf("tempo: %d\n", currentTime); // debug

        int all_done = 1;
        for (int i = 0; i < numberOfTasks; i++) {
            if (currentTime % task[i].t == 0) { // resets task when period is over
                task[i].done = 0;
                task[i].run = 0;
                task[i].deadline = task[i].t;
            }

            if (task[i].t % totalTime == 0) {
                if (currentTime == (totalTime - 1)) {
                    task[i].killed++;
                }
            }

            if (task[i].done == 0) {
                all_done = 0;
            }
        }

        if (all_done) {
            totalIdle ++;
        } else {
            if (totalIdle > 0) {
                fprintf(output, "idle for %d units\n", totalIdle);
                totalIdle = 0;
            }
        }

        // run tasks by deadline
        for (int i = 0; i < numberOfTasks; i++) {
            task[i].unit = 0;
            if (task[i].done == 0 && currentTime != totalTime) {
                while (task[i].run < task[i].c) {
                    //printf("running %s. time: %d\n", task[i].name, currentTime); // debug
                    task[i].run++;
                    task[i].unit++;
                    currentTime++;

                    int flag = 0;
                    for (int j = 0; j < numberOfTasks; j++) { // decrements deadline each time
                        task[j].deadline--;
                        if (currentTime % task[j].t == 0) { // resets task when period is over
                            task[j].done = 0;
                            task[j].deadline = task[j].t;
                        }

                        if (task[j].done == 0 && task[j].deadline < task[i].deadline) { // checks if other deadline has most priority
                            flag = 1;
                            taskExecuted = 1;
                            fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].unit, 'H');
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }

                    if ((currentTime) % task[i].t == 0 && currentTime != totalTime) { // resets task when period is over
                        if (task[i].done == 0) {
                            taskExecuted = 1;
                            fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].unit, 'L');
                            task[i].lost_deadline++;
                            break;
                        }
                        task[i].done = 0;
                        task[i].deadline = task[i].t;

                        task[i].run = 0;
                    }

                    if ((currentTime) == totalTime) {
                        taskExecuted = 1;
                        fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].run, 'K');
                        task[i].killed++;
                        break;
                    }
                }

                if (task[i].run == task[i].c) { // checks if task is finished
                    task[i].done = 1;
                    task[i].run = 0;
                    task[i].deadline = task[i].t;
                    taskExecuted = 1;
                    fprintf(output, "[%s] for %d units - %c\n", task[i].name, task[i].unit, 'F');
                    task[i].unit = 0;
                    task[i].completed++;
                }
            }
        }

        if (!taskExecuted) { // only increments here if idle
            currentTime++;
        }

        if (currentTime == totalTime) {
            for (int i = 0; i < numberOfTasks; i++) {
                if (totalTime % task[i].t == 0) {
                    task[i].killed++;
                }
            }
        }
    }

    if (totalIdle > 0) {
        fprintf(output, "idle for %d units\n", totalIdle);
    }

    Task *original_order_task = (Task *)malloc(numberOfTasks * sizeof(Task));
    if (original_order_task == NULL) {
        free(unsorted_task);
        free(task);
        free(original_indices);
    }
    for (int i = 0; i < numberOfTasks; i++) {
        original_order_task[original_indices[i]] = task[i];
    }


    fprintf(output, "\nLOST DEADLINES\n");
    for (int i = 0; i < numberOfTasks; i++) {
      fprintf(output, "[%s] %d\n", original_order_task[i].name, original_order_task[i].lost_deadline);
    }

    fprintf(output, "\nCOMPLETE EXECUTION\n");
    for (int i = 0; i < numberOfTasks; i++) {
      fprintf(output, "[%s] %d\n", original_order_task[i].name, original_order_task[i].completed);
    }

    fprintf(output, "\nKILLED\n");
    for (int i = 0; i < numberOfTasks; i++) {
        if (i != (numberOfTasks - 1)) {
            fprintf(output, "[%s] %d\n", original_order_task[i].name, original_order_task[i].killed);
        }
        else {
            fprintf(output, "[%s] %d", original_order_task[i].name, original_order_task[i].killed);
        }
    }
    free(unsorted_task);
    free(task);
    free(original_indices);
    fclose(output);
}

void bubbleSort(Task *arr, int n, int *original_indices) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].t > arr[j + 1].t) {
                Task temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                int temp_index = original_indices[j];
                original_indices[j] = original_indices[j + 1];
                original_indices[j + 1] = temp_index;
            }
        }
    }
}

Task* readTasksFromFile(char *filename, int *totalTime, int *numberOfTasks) {
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        return NULL;
    }

    if (fscanf(input, "%d", totalTime) != 1) {
        fclose(input);
        return NULL;
    }

    Task *task = NULL;
    *numberOfTasks = 0;

    task = (Task *)malloc(sizeof(Task));
    if (task == NULL) {
        fclose(input);
        return NULL;
    }

    while (fscanf(input, "%s %d %d", task[*numberOfTasks].name, &task[*numberOfTasks].t, &task[*numberOfTasks].c) == 3) {
        (*numberOfTasks)++;

        Task *temp = (Task *)realloc(task, (*numberOfTasks + 1) * sizeof(Task));
        if (temp == NULL) {
            fclose(input);
            free(task);
            return NULL;
        }
        task = temp;
    }
    fclose(input);
    return task;
}