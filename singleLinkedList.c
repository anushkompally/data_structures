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
	head-next = NULL;
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
// bool search(Node *head, int num)
// {
// 	while(head->next != NULL)
// 	{
// 		if(head->data == num)
// 			return true;
// 		else
// 			head = head->next;
// 	}
// 	return false;
// }

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


int main(void) {
	Node* node = (Node*) malloc (sizeof(Node));
	addNodeAtEnd(node,3);
	addNodeAtEnd(node,4);
	addNodeAtEnd(node,4);
	addNodeAtEnd(node,5);
	printList(node);
	printf("\n%d",getCount(node));

	addNodeAtFront(node,10);
	printf("\n");
	printList(node);
	printf("\n%d",getCount(node));

	addNodeAtNth(node,15,2);
	printf("\n");
	printList(node);
	printf("\n%d",getCount(node));

	deleteAtEnd(node);
	printf("\n");
	printList(node);
	if(search(node,4))
		printf("\n%d",getCount(node));
	return 0;
}
