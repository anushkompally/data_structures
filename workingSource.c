#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// A structure to represent a stack
struct stack
{
    int top;
    unsigned capacity;
    int* array;
};

typedef struct stack Stack;

struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;

void printList(Node* n)
{
	while (n != NULL)
	{
		printf("%d\t",n->data);
		n = n->next;
	}
}

//This function adds a node at the end of linkedlist
void addNodeAtEnd(Node *head, int data)
{
	while(head->next != NULL)
		{
			head = head->next;
		}

	head->next = (Node*) malloc (sizeof(Node));
	head->next->next = NULL;
	head->next->data = data;
}

//This function returns the number of nodes in a linkedlist
int getCount(Node *head)
{
	if(head->next == NULL)
		return 0;
	else
		return 1+getCount(head->next);
}
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

bool isPalindrome(Node* head)
{
	int len = getCount(head);
	Node* tempHead = head;
	Stack* IHOP = initStack(len);

	while(tempHead->next != NULL)
	{
		tempHead = tempHead->next;
		push(IHOP,tempHead->data);
	}

	int i = 0;
	while(i!=(len+1)/2)
	{
		if(pop(IHOP) != head->next->data)
			return false;
		head= head->next;
		i++;
	}
	return true;
}

int main(void) {
	Node* node = (Node*) malloc (sizeof(Node));
	addNodeAtEnd(node,5);
	addNodeAtEnd(node,8);
	addNodeAtEnd(node,5);
  printList(node);
  if(isPalindrome(node))
    printf("The LinkedList is a Palindrome");
	// printList(node);
	return 0;
}
