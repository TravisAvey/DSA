#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
  struct Node *next;
  uint8_t data;
};

// add a node to the list, creates a node and appends to end of list
void appendNode(uint8_t data, struct Node **head);

// add a node to the beginning of the list
void preprendNode(uint8_t data, struct Node **head);

// delete a node. assumption that the list contains only one data object
void deleteNode(uint8_t data, struct Node **head);

// checks if data is already in the list
bool contains(uint8_t data, struct Node *head);

// reverses the linked-list
void reverse(struct Node **head);

// helper function to print out the list
void printList(struct Node *head);

int main(int argc, char *argv[]) {

  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  printList(head);

  if (contains(10, head)) {
    printf("10 is in list\n");
  } else {
    printf("10 is not in list\n");
  }
  appendNode(8, &head);
  appendNode(12, &head);
  appendNode(9, &head);
  printList(head);
  preprendNode(7, &head);
  if (contains(7, head)) {
    printf("7 is in list\n");
  } else {
    printf("7 is not in list\n");
  }
  printList(head);
  reverse(&head);
  printList(head);

  return 0;
}

// add a node to the list, via the data
void appendNode(uint8_t data, struct Node **head) {
  if (contains(data, *head)) {
    printf("%d is already in this list\n", data);
    return;
  }

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

void deleteNode(uint8_t data, struct Node **head) {
  if (!head) {
    printf("list is empty\n");
    return;
  }
}

void preprendNode(uint8_t data, struct Node **head) {
  if (contains(data, *head)) {
    printf("%d is already in this list\n", data);
    return;
  }

  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;

  struct Node *p;
  p = *head;
  node->next = p;
  *head = node;
}

void reverse(struct Node **head) {

  struct Node *prev = NULL;
  struct Node *next = NULL;
  struct Node *curr = *head;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  *head = prev;
}

bool contains(uint8_t data, struct Node *head) {
  if (!head) {
    return false;
  }

  struct Node *p = head;

  while (p) {
    if (p->data == data) {
      return true;
    }
    p = p->next;
  }

  return false;
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
