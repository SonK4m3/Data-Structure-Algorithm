							/**		Circular Linked List	**/
/*
	- A circular linked list is a variation of a linked list in which the last
	element is linked to the first element. This forms a circular loop.	
	
	- A circular linked list can be either singly linked or doubly linked.
		1. for singly linked list, next pointer of last item points to the first item.
		2. In the doubly linked list, prev pointer of the first item points 
		to the last item as well.
		
	- Insertion on a Circular Linked List
		1. insertion at the begging
		2. insertion in-between nodes
		3. insertion at the end
	
	- Deletion on a Circular Linked List
		1. If the node to be deleted is the only node
		2. If last node is to be deleted
		3. If any other nodes are to be deleted
 
	- Circular Linked List Complexity
					Time			 Space
	Insertion		O(1) or O(n)	O(1)
	Deletion		O(1)			O(1)
	
	- Why Circular Linked list?
		1. The NULL assignment is not required because a node always point to another node.
		2. The starting point can be set to any node.
		3. Traversal from the first node to the last node is quick.
	
	- Applications
		1. It is used in multiplayer games to give a chance to each player to play the game.
		
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
}node;

node* addToEmpty(node* last, int data){
	if(last != NULL) return last;
	// allocate memory to the new node
	node* newNode = (node*)malloc(sizeof(node));
	
	// assign data to the new node
	newNode->data = data;
	
	// assign last to newNode
	last = newNode;
	
	// create link to iteslf
	last->next = last;
	
	return last;
}

// add node to the front
node* addFront(node* last, int data){
	if(last == NULL) return addToEmpty(last, data);
	
	//allocate memory to the new node
	node* newNode = (node*)malloc(sizeof(node));
	
	// add data to the node
	newNode->data = data;
	
	// store the address of the current first node in the last
	newNode->next = last->next;
	
	// make newNode as head
	last->next = newNode;
	
	return last;
}

// add node to the end
node* addEnd(node* last, int data){
	//check if the node is empty
	if(last == NULL)	return addToEmpty(last, data);
	
	// allocate memory to the new node
	node* newNode = (node*)malloc(sizeof(node));
	
	// add data to the node
	newNode->data = data;
	
	// store the address of the head node to next of newNode
	newNode->next = last->next;
	
	// point the current last node to the newNode
	last->next = newNode;
	
	// make newNode as the last node
	last = newNode;
	
	return last;
}

// insert node after a specific node
node* addAfter(node* last, int data, int item){
	// check if the list is empty
	if (last == NULL) return NULL;
	
	node *newNode, *p;
	
	p = last->next;
	do{
		// if the item is found, place newNode after it
		if(p->data == item) {
			newNode = (node*)malloc(sizeof(node));
			
			newNode->data = data;
			
			newNode->next = p->next;
			
			p->next = newNode;	
		
			if(p == last) last = newNode;
			return last;
		}
		p = p->next;
	} while(p != last->next);
	
	cout << "\nThe given node is not present in the list" << endl;
	return last;
}

//delete a node
void deleteNode(node** last, int key){
	// if linked list is empty
	if(*last == NULL) return;
	
	// if the list contains only a single node
	if((*last)->data == key && (*last)->next == *last) {
		free(*last);
		*last = NULL;
		return;
	}
	
	Node* tmp = *last, *d;
	
	// if last is to be deleted
	if((*last)->data == key) {
		// find the node before the last node
		while(tmp->next != *last) tmp = tmp->next;
		
		tmp->next = (*last)->next;
		free(*last);
		*last = tmp->next;
	}
	
	// travel to the node to be deleted
	while(tmp->next != *last && tmp->next->data != key)
		tmp = tmp->next;
		
	// if node to be deleted was found
	if(tmp->next->data == key) {
		d= tmp->next;
		tmp->next = d->next;
		free(d);
	}
}

void traverse(node* last){
	node* p;
	
	if(last == NULL){
		cout << "The list is empty" << endl;
		return;
	}
	
	p = last->next;
	
	do{
		cout << p->data <<" ";
		p = p->next;
	} while (p != last->next);
}

void Simple_Circular_Linked_List(){
	node* last;
	node* one = NULL, *two = NULL, * three = NULL;
	
	// Allocate memory
	one = (node*)malloc(sizeof(node));
	two = (node*)malloc(sizeof(node));
	three = (node*)malloc(sizeof(node));
	
	// assign data value
	one->data = 1;
	two->data = 2;
	three->data = 3;
	
	// connect nodes
	one->next = two;
	two->next = three;
	three->next = one;
	
	// save address of third node in last
	last = three;
}

int main(){
	node* last = NULL;
	
	last = addToEmpty(last, 6);
	last = addEnd(last, 8);
	last = addFront(last, 2);
	
	last = addAfter(last, 10, 2);
	
	traverse(last);
	
	deleteNode(&last, 8);
	cout << endl;
	
	traverse(last);
	
	return 0;
}
