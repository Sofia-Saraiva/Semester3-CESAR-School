#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int gold;
  int silver;
  int bronze;
  char *country;
  struct Node *next;
  struct Node *prev;
} Node;

void insertion(Node **head, int gold, int silver, int bronze, const char *country);
void bubbleSort(Node **head);
void printLista(Node *head);

int main(void) {
  int N, gold, silver, bronze;
  char country[100];
  Node *head = NULL;
  
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s %d %d %d", country, &gold, &silver, &bronze);
    insertion(&head, gold, silver, bronze, country);
  }
  
  bubbleSort(&head);
  printLista(head);
  
  return 0;
}


void insertion(Node **head, int gold, int silver, int bronze, const char *country) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (new_node != NULL) {
    new_node->gold = gold;
    new_node->silver = silver;
    new_node->bronze = bronze;
    new_node->country = (char *)malloc(strlen(country) + 1);
    strcpy(new_node->country, country);
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if (*head == NULL) {
      *head = new_node;
    }
    else {
      Node *current = *head;
      while (current->next != NULL) {
          current = current->next;
      }
      current->next = new_node;
      new_node->prev = current;
    }
  }
}

void bubbleSort(Node **head) {
  if (*head != NULL || (*head)->next == NULL) {
    int swapped;
    
    do {
      swapped = 0;
      Node *current = *head;
      
      while (current->next != NULL) {
        int needswap = 0;
 
        if (current->gold < current->next->gold) {
          needswap = 1;
        }
        else if (current->gold == current->next->gold) {
          if (current->silver < current->next->silver) {
            needswap = 1;
          }
          else if (current->silver == current->next->silver) {
            if (current->bronze < current->next->bronze) {
              needswap = 1;
            }
            else if (current->bronze == current->next->bronze) {
              if (strcmp(current->country, current->next->country) > 0) {
                needswap = 1;
              }
            }
          }
        }
          
        if (needswap) {
          Node *temp = current->next;

          current->next = temp->next;
          temp->prev = current->prev;

          if (current->prev) {
              current->prev->next = temp;
          } else {
              *head = temp;
          }

          if (temp->next) {
              temp->next->prev = current;
          }

          temp->prev = current->prev;
          current->prev = temp;

          current->next = temp->next;
          temp->next = current;

          swapped = 1;
          } else {
          current = current->next;
          }
        }
      
    } while (swapped);
  }
}

void printLista(Node *head) {
  if (head != NULL) {
    while (head != NULL) {
      printf("%s ", head->country);
      printf("%d ", head->gold);
      printf("%d ", head->silver);
      printf("%d", head->bronze);
      head = head->next;
      printf("\n");
    } 
  }
}