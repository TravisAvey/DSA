#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int size;
  int top;
  int *data;
};

int peek(struct Stack *stack);
int pop(struct Stack *stack);
void push(struct Stack *stack, int data);
struct Stack *newStack(uint8_t size);
void printStack(struct Stack *stack);

int main(int argc, char *argv[]) {

  struct Stack *stack = newStack(4);
  push(stack, 7);
  push(stack, 42);
  push(stack, 32);
  push(stack, 12);
  push(stack, 88);
  printStack(stack);
  printf("pop: %d\n", pop(stack));
  printf("peek: %d\n", peek(stack));
  return 0;
}

struct Stack *newStack(uint8_t size) {

  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
  s->size = size;
  s->top = -1;
  s->data = (int *)malloc(sizeof(int) * size);

  return s;
}

void push(struct Stack *stack, int data) {
  // check if at max of our stack array
  if (stack->top == stack->size - 1) {
    // double size and copy
    stack->size *= 2;
    int *data = (int *)malloc(sizeof(int) * stack->size);
    for (int i = 0; i <= stack->top; i++) {
      data[i] = stack->data[i];
    }
    stack->data = data;
  }
  // prefix add one to move to next loc of stack and store data
  stack->data[++stack->top] = data;
}

int pop(struct Stack *stack) {
  // if top is at -1, it's empty
  if (stack->top == -1) {
    printf("stack is empty\n");
    return -1;
  }
  // postfix: return the data then decrement by 1
  return stack->data[stack->top--];
}

int peek(struct Stack *stack) { return stack->data[stack->top]; }

void printStack(struct Stack *stack) {
  printf("Top: %d\n", stack->top);
  printf("Size: %d\n", stack->size);
  printf("Data:\n");
  for (int i = 0; i <= stack->top; i++) {
    printf("\t%d\n", stack->data[i]);
  }
}
