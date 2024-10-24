// C++ program to merge K sorted doubly
// linked list in sorted order
#include <bits/stdc++.h>
using namespace std;

// A linked list node
struct Node {
	int data;
	Node* next;
	Node* prev;
};

// Given a reference (pointer to pointer) to the head
// Of a DLL and an int, appends a new node at the end
void append(struct Node** head_ref, int new_data)
{
	// Allocate node
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref;

	// Put in the data
	new_node->data = new_data;

	// This new node is going to be the last
	// node, so make next of it as NULL
	new_node->next = NULL;

	// If the Linked List is empty, then make
	// the new node as head */
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	// Else traverse till the last node
	while (last->next != NULL)
		last = last->next;

	// Change the next of last node
	last->next = new_node;

	// Make last node as previous of new node
	new_node->prev = last;

	return;
}

// Function to print the list
void printList(Node* node)
{
	Node* last;

	// Run while loop unless node becomes null
	while (node != NULL) {
		cout << node->data << " ";
		last = node;
		node = node->next;
	}
}

// Function to merge two
// sorted doubly linked lists
Node* mergeList(Node* p, Node* q)
{
	Node* s = NULL;

	// If any of the list is empty
	if (p == NULL || q == NULL) {
		return (p == NULL ? q : p);
	}

	// Comparison the data of two linked list
	if (p->data < q->data) {
		p->prev = s;
		s = p;
		p = p->next;
	}
	else {
		q->prev = s;
		s = q;
		q = q->next;
	}

	// Store head pointer before merge the list
	Node* head = s;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {

			// Changing of pointer between
			// Two list for merging
			s->next = p;
			p->prev = s;
			s = s->next;
			p = p->next;
		}
		else {

			// Changing of pointer between
			// Two list for merging
			s->next = q;
			q->prev = s;
			s = s->next;
			q = q->next;
		}
	}

	// Condition to check if any anyone list not end
	if (p == NULL) {
		s->next = q;
		q->prev = s;
	}
	if (q == NULL) {
		s->next = p;
		p->prev = s;
	}

	// Return head pointer of merged list
	return head;
}

// Function to merge all sorted linked
// list in sorted order
Node* mergeAllList(Node* head[], int k)
{
	Node* finalList = NULL;
	for (int i = 0; i < k; i++) {

		// Function call to merge two sorted
		// doubly linked list at a time
		finalList = mergeList(finalList, head[i]);
	}

	// Return final sorted doubly linked list
	return finalList;
}

// Driver code
int main()
{
	int k = 3;
	Node* head[k];

	// Loop to initialize all the lists to empty
	for (int i = 0; i < k; i++) {
		head[i] = NULL;
	}

	// Create first doubly linked List
	// List1 -> 1 <=> 5 <=> 9
	append(&head[0], 1);

	append(&head[0], 5);

	append(&head[0], 9);

	// Create second doubly linked List
	// List2 -> 2 <=> 3 <=> 7 <=> 12
	append(&head[1], 2);

	append(&head[1], 3);

	append(&head[1], 7);

	append(&head[1], 12);

	// Create third doubly linked List
	// List3 -> 8 <=> 11 <=> 13 <=> 18
	append(&head[2], 8);

	append(&head[2], 11);

	append(&head[2], 13);

	append(&head[2], 18);

	// Function call to merge all sorted
	// doubly linked lists in sorted order
	Node* finalList = mergeAllList(head, k);

	// Print final sorted list
	printList(finalList);

	return 0;
}
