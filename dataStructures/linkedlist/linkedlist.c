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

  appendNode(8, &head);
  appendNode(12, &head);
  appendNode(9, &head);

  printf("should be 8-12-9...\n");
  printList(head);

  preprendNode(1, &head);
  appendNode(13, &head);

  printList(head);

  return 0;
}

// add a node to the list, via the data
void appendNode(uint8_t data, struct Node **head) {
  if (contains(data, *head)) {
    printf("%d is already in this list\n", data);
    return;
  }

  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->data = data;
  n->next = NULL;

  if (*head == NULL) {
    *head = n;
  } else {
    struct Node *p = *head;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = n;
  }
}

void deleteNode(uint8_t data, struct Node **head) {
  if (!head) {
    printf("list is empty\n");
    return;
  }
  struct Node *curr = *head;
  struct Node *prev = NULL;

  while (curr) {
    if (curr->data == data) {
      prev->next = curr->next;
    }
    prev = curr;
    curr = curr->next;
  }
}

void preprendNode(uint8_t data, struct Node **head) {
  if (contains(data, *head)) {
    printf("%d is already in this list\n", data);
    return;
  }

  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (!node) {
    printf("error creating node\n");
    return;
  }

  node->data = data;

  node->next = *head;
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

  if (head->next == NULL)
    return;

  struct Node *p = head;
  printf("head -> ");
  while (p->next != NULL) {
    printf("%d -> ", p->data);
    p = p->next;
  }
  printf("%d -> END\n", p->data);
}
