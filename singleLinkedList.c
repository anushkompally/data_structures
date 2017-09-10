#include <stdio.h>
#include <stdlib.h>
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

void buildList(Node *head, int data)//Adding node at the end.
{
	while(head->next != NULL)
		{
			head = head->next;
		}

	head->next = (Node*) malloc (sizeof(Node));
	head->next->next = NULL;
	head->next->data = data;
}


int main(void) {
	Node* node = (Node*) malloc (sizeof(Node));
	buildList(node,3);
	buildList(node,4);
	buildList(node,4);
	buildList(node,5);
	printList(node);
	return 0;
}
