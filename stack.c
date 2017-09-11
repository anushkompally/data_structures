#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.>

// A structure to represent a stack
struct stack
{
    int top;
    unsigned capacity;
    int* array;
};

typedef struct stack Stack;

Stack* initStack(unsigned capacity)
{
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc (stack->capacity*sizeof(int));
  return stack;
}

bool isEmpty(Stack* stack)
{
  return stack->top == -1;
}

bool isFull(Stack *stack)
{
  return stack->top + 1 == stack->capacity;
}

void push(Stack *stack, int num)
{
  if(isFull(stack))
    return;
  stack->array[++stack->top] = num;
}

int pop(Stack *stack)
{
  if(isEmpty(stack))
    return INT_MIN;
  return stack->array[stack->top--];
}

void printStack(Stack* stack)
{
  int i;
  while(i<=stack->top)
  {
    printf("%d\t",stack->array[i++]);
  }
}

int main()
{
  Stack* IHOP = initStack(10);
  push(IHOP,2);
  push(IHOP,10);
  push(IHOP,4);
  push(IHOP,33);
  pop(IHOP);
  printStack(IHOP);
  return 0;

}
