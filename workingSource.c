#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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


bool compareLists(Node* head1, Node* head2)
{
	Node* temp1 = head1;
	Node* temp2 = head2;

	while(temp1 && temp2)
	{
		if(temp1->next->data == temp2->next->data)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return false;
	}
	if(temp1 == NULL && temp2 == NULL)
		return true;
	return false;
}


int main(void) {
	Node* head1 = (Node*) malloc (sizeof(Node));
	addNodeAtEnd(head1,5);
	addNodeAtEnd(head1,8);
	addNodeAtEnd(head1,5);
  printList(head1);

  Node* head2 = (Node*) malloc (sizeof(Node));
	addNodeAtEnd(head2,5);
	addNodeAtEnd(head2,8);
	addNodeAtEnd(head2,5);
  printf("\n");
  printList(head2);

  if(compareLists(head1,head2))
  {
    printf("\n");
    printf("Lists are same");
  }

	return 0;
}
