#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

//This function adds a node at the front of linkedlist
void addNodeAtFront(Node *head,int data)
{

	Node *temp = (Node*) malloc (sizeof(Node));
	temp->data = data;
	temp->next = head->next;

	head->next = temp;

}

//This function adds a node at the nth location in a linkedlist
void addNodeAtNth(Node *head,int data,int nth)
{
	Node *temp = (Node*) malloc (sizeof(Node));
	temp->data = data;

	while(nth-1)
	{
		head = head->next;
		nth--;
	}

	temp->next = head->next;
	head->next = temp;
}

void deleteAtEnd(Node *head)
{
	while(head->next->next != NULL)
		head=head->next;
	head->next = NULL;
	free(head->next);
}

//This function returns the number of nodes in a linkedlist
int getCount(Node *head)
{
	if(head->next == NULL)
		return 0;
	else
		return 1+getCount(head->next);
}

//This function return true if the integer is found in the linkedlist -- Iterative
bool search_Iterative(Node *head, int num)
{
	while(head->next != NULL)
	{
		if(head->data == num)
			return true;
		else
			head = head->next;
	}
	return false;
}

//This function return true if the integer is found in the linkedlist -- Recursive
bool search(Node *head, int num)
{
	if(head == NULL)
		return false;
	else if(head->data == num)
		return true;
	else
		return search(head->next, num);
}

//This fucntion adds a number in an sorted LL
Node* insert(Node* head, int num)
{
	if (head == NULL)
		return NULL;

	Node* node = (Node*) malloc (sizeof(Node));
	node->data = num;

	while(head->next != NULL && head->next->data < num)
	{
		head = head->next;
	}

	node->next = head->next;
	head->next = node;
	return head;
}

/********************************************************************/
//Function to check if a Linkedlist is a palidrome - Using a STACK
/********************************************************************/
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
	addNodeAtEnd(node,10);
	addNodeAtFront(node,3);
	deleteAtEnd(node);
	printList(node);

	insert(node,4);
	insert(node,6);
	printf("\n");
	printList(node);
	return 0;
}
