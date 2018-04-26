/* -------------------linked_list.cpp-----------------*/
/* Basic Linked List Operations */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int DataItem;

struct Node {
	DataItem data;
	Node *next;
};

// Functions Prototypes
Node* ListSearch(DataItem value, Node *head);
void InsertNewLast(DataItem value, Node **L);
void DeleteLastNode(Node **L);
void PrintList(Node *head);

int main()
{
	Node *head; // Declare list header as a pointer to Node
	Node *nodePtr; // used as return value for ListSearch
	DataItem searchValue;
	head = NULL; // set list to empty.
	// Some examples of function calls:
	// Printing and Inserting...
	PrintList(head);
	InsertNewLast(10, &head);
	PrintList(head);
	InsertNewLast(20, &head);
	PrintList(head);
	InsertNewLast(30, &head);
	PrintList(head);
	InsertNewLast(40, &head);
	PrintList(head);
	InsertNewLast(50, &head);
	PrintList(head);
	// Searching...
	searchValue = 20;
	nodePtr = ListSearch(searchValue, head);
	if (nodePtr != NULL)
	{
		cout << "Search value " << searchValue << " was FOUND" << endl;
	}
	else
	{
		cout << "Search value " << searchValue << " was NOT FOUND" << endl;
	}
	searchValue = 5;
	nodePtr = ListSearch(searchValue, head);
	if (nodePtr != NULL)
	{
		cout << "Search value " << searchValue << " was FOUND\n";
	}
	else
	{
		cout << "Search value " << searchValue << " was NOT FOUND\n";
	}
	searchValue = 40;
	nodePtr = ListSearch ( searchValue, head );
	if (nodePtr != NULL)
	{
		cout << "Search value " << searchValue << " was FOUND\n";
	}
	else
	{
		cout << "Search value " << searchValue << " was NOT FOUND\n";
	}
	// Deleting and Printing...
	DeleteLastNode(&head);
	PrintList(head);
	DeleteLastNode(&head);
	PrintList(head);
	DeleteLastNode(&head);
	PrintList(head);
	DeleteLastNode(&head);
	PrintList(head);
	DeleteLastNode(&head);
	PrintList(head);

	return 0;
}

// This function searches for a node in the list whose data field
// equals to value. It returns a pointer to such node if it finds it.
// Otherwise, it returns NULL.
Node* ListSearch(DataItem value, Node *head)
{
	if (head == NULL) return NULL;
	Node* current = head; 
	while (current != NULL)
	{
		if (current->data == value)
			return head; 
		current = current->next;
	}
	return NULL;
}

// This function inserts a new node with data field set to
// value at the end of the list. L points to the pointer of the first
// node, or NULL if the list is empty.
void InsertNewLast(DataItem value, Node **L)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = NULL;

	if (*L == NULL)
	{
		*L = newNode;
	}
	else
	{
		Node* last =*L;
		while (last->next != NULL)
		{
			last = last->next;
		}

		last->next = newNode;
	}
}

// This function deletes a node from the back end (tail) of the list.
// L points to the pointer of the first node, or NULL if the list is empty.
void DeleteLastNode(Node **L)
{
	if (*L != NULL && (*L)->next != NULL)
	{
		Node* last = (*L);
		while (last->next->next != NULL)
			last = last->next;

		delete last->next;
		last->next = NULL;	
	}
	else
	{
		delete *L;
		*L = NULL;
	}
}

// This function displays the current elements of the list.
void PrintList(Node *head)
{
	if (head == NULL) return;
	Node* current = head;
	while(current != NULL)
	{
		cout << "[" << current->data << "]";
		current = current->next;
		if (current != NULL)  
			cout << "->";
	}
	cout << endl;
}

/* -------------------linked_list.cpp-----------------
The following are call examples that can be used in the main function.
int main ()
{
Node *head; // Declare list header as a pointer to Node
Node *nodePtr; // used as return value for ListSearch
DataItem searchValue;
head = NULL; // set list to empty.
// Some examples of function calls:
// Printing and Inserting...
PrintList(head);
InsertNewLast(10, &head);
PrintList(head);
InsertNewLast(20, &head);
PrintList(head);
InsertNewLast(30, &head);
PrintList(head);
InsertNewLast(40, &head);
PrintList(head);
InsertNewLast(50, &head);
PrintList(head);
// Searching...
searchValue = 20;
nodePtr = ListSearch(searchValue, head);
if (nodePtr != NULL)
{
cout << "Search value " << searchValue << " was FOUND" << endl;
}
else
{
cout << "Search value " << searchValue << " was NOT FOUND" << endl;
}
sarchValue = 5;
nodePtr = ListSearch(searchValue, head);
if (nodePtr != NULL)
{
cout << "Search value " << searchValue << " was FOUND\n";
}
else
{
cout << "Search value " << searchValue << " was NOT FOUND\n";
}
searchValue = 40;
nodePtr = ListSearch ( searchValue, head );
if (nodePtr != NULL)
{
cout << "Search value " << searchValue << " was FOUND\n";
}
else
{
cout << "Search value " << searchValue << " was NOT FOUND\n";
}
// Deleting and Printing...
DeleteLastNode(&head);
PrintList(head);
DeleteLastNode(&head);
PrintList(head);
DeleteLastNode(&head);
PrintList(head);
DeleteLastNode(&head);
PrintList(head);
DeleteLastNode(&head);
PrintList(head);
system("pause");
}
*/