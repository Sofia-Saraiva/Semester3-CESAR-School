#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

void initialize(Node** head, Node** tail, int data); 
int emptyList(Node* head);
Node* clockwise(int k, Node *selected);
Node* counterClock(int m, Node *selected);
void removeSelected(Node **head, Node **tail, Node *selected);
void printSelecteds(int data1, int data2);

int main(void) {
  int N; // size of the list
  int k; // positions clockwise
  int m; // positions counter-clockwise

  do {
    scanf("%d %d %d", &N, &k, &m);
    Node* head = NULL;
    Node* tail = NULL;
    Node* selectedClock = NULL;
    Node* selectedCounter = NULL;
    Node* cursorClock = NULL;
    Node* cursorCounter = NULL;

    initialize(&head, &tail, N);

    while (!emptyList(head)) {
      
      if (selectedClock == NULL) { 
        selectedClock = clockwise(k, head);
      }
      else {
        selectedClock = clockwise(k, cursorClock);
      }

      if (selectedCounter == NULL) {
        selectedCounter = counterClock(m, tail);
      }
      else {
        selectedCounter = counterClock(m, cursorCounter);
      }

      cursorClock = selectedClock->next;
      cursorCounter = selectedCounter->prev;

      if (cursorClock == selectedCounter) {
        cursorClock = cursorClock->next;
      }
      if (cursorCounter == selectedClock) {
        cursorCounter = cursorCounter->prev;
      }

      if (selectedClock == selectedCounter) {
        printSelecteds(selectedClock->data, selectedClock->data);
        removeSelected(&head, &tail, selectedClock);
      }
      else {
        printSelecteds(selectedClock->data, selectedCounter->data);
        removeSelected(&head, &tail, selectedClock);
        removeSelected(&head, &tail, selectedCounter);
      }
      
      if (!emptyList(head)) {
        printf(",");
      }
      else {
        printf("\n");
      }
    }  
  } while(N != 0 && k != 0 && m != 00);

  return 0;
}

int emptyList(Node* head) {
  if (head == NULL) {
    return 1;
  }  
  else {
    return 0;
  }
}

void initialize(Node** head, Node** tail, int data) {
  int selected = 1;
  while (selected <= data) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = selected; 

    if (*head == NULL) {
      *head = *tail = new_node;
      new_node->prev = new_node->next = new_node;
    }
    else {
      (*tail)->next = new_node;
      new_node->prev = *tail;
      new_node->next = *head;
      (*head)->prev = new_node;
      *tail = new_node;
    }
    selected++;
  }
}

Node* clockwise(int k, Node *selected) {
  while (k > 1) {
    selected = selected->next;
    k--;
  }
  return selected;
}

Node* counterClock(int m, Node *selected) {
  while (m > 1) {
    selected = selected->prev;
    m--;
  }
  return selected;
}

void removeSelected(Node **head, Node **tail, Node *selected) {
  if (selected == *head) {
    if (*head == *tail) {
      *head = *tail = NULL;
    }
    else {
      *head = selected->next;
      (*tail)->next = *head;
      (*head)->prev = *tail;
    }
    free(selected);
  }
  else if (selected == *tail) {
    *tail = selected->prev;
    (*tail)->next = *head;
    (*head)->prev = *tail;
    free(selected);
  }
  else {
    selected->prev->next = selected->next;
    selected->next->prev = selected->prev;
    free(selected);
  } 
}

void printSelecteds(int data1, int data2) {
    int numDigits1 = (data1 >= 10) ? 2 : 1;

    if (numDigits1 == 2) {
        printf(" ");
    } else {
        printf("  ");
    }
    printf("%d", data1);

    if (data1 != data2) {
      int numDigits2 = (data2 >= 10) ? 2 : 1;
      if (numDigits2 == 2) {
        printf(" ");
      } else {
        printf("  ");
      }
      printf("%d", data2);
    }
}
