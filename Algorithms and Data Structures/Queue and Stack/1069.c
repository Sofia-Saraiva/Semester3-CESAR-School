#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node **head, int n);
int pop(Node **head);
void freeStack(Node **head);

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
      char string[999];
      scanf("%s", string);

      Node *head = NULL;
      int diamond = 0;

      for (int j = 0; string[j] != '\0'; j++) {
        if (string[j] == '<') {
            push(&head, 0);
        } 
        else if (j != 0 && string[j] == '>' && head != NULL) {
          diamond++;
          pop(&head);
        }
      }

      printf("%d\n", diamond);
      freeStack(&head);
  }
  return 0;
}

void push(Node **head, int n) {
  Node *new = (Node *)malloc(sizeof(Node));

  if (new != NULL) {
    new->data = n;
    new->next = *head;
    *head = new;
  }
}

int pop(Node **head) {
  int n = 0;

  if ((*head) != NULL) {
    n = (*head)->data;
    Node *aux = *head;
    *head = (*head)->next;
    free(aux);
  }
  return n;
}

void freeStack(Node **head) {
  while (*head != NULL) {
    pop(head);
  }
}
