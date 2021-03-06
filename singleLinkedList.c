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

bool compareLists(Node* head1, Node* head2)
{
	Node* temp1 = head1;
	Node* temp2 = head2;

	while(temp1 && temp2)
	{
		if(temp1->data == temp2-->data)
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

/********************************************************************/
//Function to check if a Linkedlist is a palidrome - Using a STACK
// Time complexity of this method is O(n) but requires O(n) extra space
/********************************************************************/
bool isPalindrome_usingStack(Node* head)
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

/********************************************************************/
//Function to check if a Linkedlist is a palidrome - By reversing the string
// Time complexity of this method is O(n)
/********************************************************************/
bool isPalindrome_Reversing(Node* head)
{

}

void reverseList(Node *head)
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

int main(void) {
	Node* node = (Node*) malloc (sizeof(Node));
	addNodeAtEnd(node,5);
	addNodeAtEnd(node,8);
	addNodeAtEnd(node,10);
	addNodeAtFront(node,3);
	deleteAtEnd(node);
	printList(node);
	reverseList(node);
	printList(node);
	return 0;
}
