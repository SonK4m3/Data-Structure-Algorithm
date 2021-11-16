						/**		Singly Linked List		**/
/*	
	- It is the most common. Each node has data and a pointer 
	to the next node.	
	
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
};
typedef struct node node;

int main(){
	node *head;
	node *one = NULL, *two = NULL, *three = NULL;
	
	one = (node*)malloc(sizeof(node));
	two = (node*)malloc(sizeof(node));
	three = (node*)malloc(sizeof(node));
	
	one->data = 1;
	two->data = 2;
	three->data = 3;
	
	one->next = two;
	two->next = three;
	three->next = NULL;
	
	head = one;
	
	cout << head->data;
	head = head->next;
	while(head != NULL){
		cout << " --> " << head->data;
		head = head->next;
	}
}
