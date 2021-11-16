					/**   Linked List Data Structure  **/
/*
	- A linked list is a linear data structure that includes a series of
	connected nodes. Each node store the data and the address of the next 
	node.
	
	- Linked list can be of multiple types: singly, doubly and circular linked list.
	
	- Linked list Complexity:
						Worst case				Average Case
		Search			O(n) 					O(n)
		Insert			O(1)					O(1)
		Deletion		O(1)					O(1)
		
	- Applications:
		1. Dynamic memory allocation.
		2. Implemented in stack and queue.
		3. In undo functionality of softwares
		4. Hash tables, Graphs.

*/
#include<bits/stdc++.h>
using namespace std;

// Creating a node
class Node {
	 public:
	int value;
	Node* next;
};

// print Linked list
void printLinkedlist(Node *p){
	cout <<"head-->" << p->value;
	p = p->next;
	while(p != NULL){
		cout << "-->" << p->value;
		p = p->next;
	}
	cout << "-->NULL";
}

int main(){
	Node* head;
	Node *one = NULL, *two = NULL, *three = NULL;
	
	// allocate 3 nodes in the heap
	one = new Node();
	two = new Node();
	three = new Node();
	
	// Assign value values
	one->value = 1;
	two->value = 2;
	three->value = 3;
	
	// Connect nodes
	one->next = two;
	two->next = three;
	three->next = NULL;
	
	head = one;
	// print linked list
	printLinkedlist(head);
}
