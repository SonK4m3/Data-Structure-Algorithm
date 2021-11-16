						/**		Doubly Linked List		**/
/*	
	- We add a pointer to the previous node in a doubly-linked list.
	Thus, we can go in either direction: forward or backward.	
	
	- Doubly Linked List Complexity
						Time	 			Space
		Insert			O(1) or O(n)		O(1)
		Deletion		O(1)				O(1)
		
	- Applicatoins
		1. Redo and undo functionaly in software
		2. Forward and backward navigation in browsers
		3. For navigation systems where forwrad and backward
			navigation is required
	
	- Differ between Singly Linked List Vs Doubly Linked List
		Singly Linked List							Doubly Linked List
	
	1.	Each node consists of a data value			Each node consists of a data value, 
		and a pointer to the next node.				a pointer to the next node, and a pointer
													to the previous node.
	2.	Traversal can occur in one way only.		Travesal can occur in both ways.
	3.	It requires less space.						It requires more space because of an
													extra pointer.
	4.	It can be implemented on the stack.			It has multiple usages. It can be implemented
													on the stack, heap, and binary tree.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node node;

void insertFront(node** head, int data){
	node* newNode = new node;
	
	// assign data to newNode
	newNode->data = data;
	
	// make newNode as a head
	newNode->next = (*head);
	
	//  assign null to prev
	newNode->prev = NULL;
	
	// previous of head
	if( (*head) != NULL)
		(*head)->prev = newNode;
		
	// head points to newNode
	(*head) = newNode;
}

// insert a node after a specific node
void insertAfter(node* prev_node, int data){
	// check if previous node is null
	if(prev_node == NULL){
		cout << "previous node cannot be null";
		return;
	}
	
	// allocate memory for newNode
	node* newNode = new node;
	
	//assign data to newNode
	newNode->data = data;
	
	// set next of newNode to next of prev node
	newNode->next = prev_node->next;
	
	//set next of prev node to newNode
	prev_node->next = newNode;
	
	//set prev of newNode to the previous node
	newNode->prev = prev_node;
	
	// set prev of newNode's next to newNode
	if(newNode->next != NULL)
		newNode->next->prev = newNode;
}

// insert a newNode at the end of the list
void insertEnd(node** head, int data) {
	// allocate memory for node
	node* newNode = new node;
	
	newNode->data = data;
	newNode->next = NULL;
	
	node* tmp = *head;
	
	if(*head == NULL){
		newNode->prev = NULL;
		*head = newNode;
		return;
	}
	
	while(tmp->next != NULL)
		tmp = tmp->next;
	
	tmp->next = newNode;
	
	newNode->prev = tmp;
}

// delete a node

void deleteNode(node** head, node* del_node){
	if(*head == NULL || del_node == NULL)
		return;
	
	if(*head == del_node)
		*head = del_node->next;
		
	if(del_node->next != NULL)
		del_node->next->prev = del_node->prev;
		
	if(del_node->prev != NULL)
		del_node->prev->next = del_node->next;
		
	free(del_node);
}

// print
void display(node* n){
	node* last;
	
	while(n != NULL){
		cout << n->data << "->";
		last = n;
		n = n->next;
	}
	if(n == NULL)
		cout << "NULL\n";
}

int main(){
	node *head = NULL;
	
	insertEnd(&head, 5);
	insertFront(&head, 1);
	insertFront(&head, 6);
	insertEnd(&head, 9);
	
	insertAfter(head->next, 15);
	display(head);
	deleteNode(&head, head->next->next->next->next);
	
	display(head);
}
