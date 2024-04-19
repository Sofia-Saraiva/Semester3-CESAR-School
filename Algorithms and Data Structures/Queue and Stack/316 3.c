#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data[100];
  struct Node *next;
} Node;

void insertion(Node **head, char *data);
void printQueues(Node *head1, Node *head2, Node *head3, Node *head4);

int main(void) {
  char str[100];
  int P;
  Node *head1 = NULL;
  Node *head2 = NULL;
  Node *head3 = NULL;
  Node *head4 = NULL;

  do {
    scanf("%s", str);

    if (str[0] == '-') {
      P = atoi(str);
    } else if (str[0] == 'A') {
      if (P == -1) {
        insertion(&head1, str);
      } else if (P == -3) {
        insertion(&head3, str);
      } else if (P == -2) {
        insertion(&head2, str);
      } else if (P == -4) {
        insertion(&head4, str);
      }
    }
  } while (str[0] != '0');

  printQueues(head1, head2, head3, head4);

  return 0;
}

void insertion(Node **head, char *data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void printQueues(Node *head1, Node *head2, Node *head3, Node *head4) {
  Node *current1 = head1;
  Node *current2 = head2;
  Node *current3 = head3;
  Node *current4 = head4;

  int firstPrinted = 0;

  while (current1 != NULL || current2 != NULL || current3 != NULL ||
         current4 != NULL) {
    if (current1 != NULL) {
      if (firstPrinted) {
        printf(" ");
      }
      printf("%s", current1->data);
      current1 = current1->next;
      firstPrinted = 1;
    }
    if (current3 != NULL) {
      if (firstPrinted) {
        printf(" ");
      }
      printf("%s", current3->data);
      current3 = current3->next;
      firstPrinted = 1;
    }
    if (current2 != NULL) {
      if (firstPrinted) {
        printf(" ");
      }
      printf("%s", current2->data);
      current2 = current2->next;
      firstPrinted = 1;
    }
    if (current4 != NULL) {
      if (firstPrinted) {
        printf(" ");
      }
      printf("%s", current4->data);
      current4 = current4->next;
      firstPrinted = 1;
    }
  }
  printf("\n");
}