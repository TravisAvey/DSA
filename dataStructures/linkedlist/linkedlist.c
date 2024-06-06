#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *next;
  uint8_t data;
};

// add a node to the list, via the data
void appendNode(uint8_t data, struct Node **head);

// helper function to print out the list
void printList(struct Node *head);

int main(int argc, char *argv[]) {

  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  printList(head);

  appendNode(8, &head);
  appendNode(12, &head);
  appendNode(9, &head);
  printList(head);

  return 0;
}

// add a node to the list, via the data
void appendNode(uint8_t data, struct Node **head) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;

  if (*head == NULL) {
    printf("head is null, adding to front of list\n");
    *head = temp;
  } else {
    struct Node *p = *head;
    while (p->next != NULL)
      p = p->next;
    p->next = temp;
  }
}

// helper function to print out the list
void printList(struct Node *head) {

  if (!head->next) {
    printf("linked-list is empty\n");
    return;
  }

  struct Node *current = head->next;

  printf("head -> ");
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf(" END\n");
}
