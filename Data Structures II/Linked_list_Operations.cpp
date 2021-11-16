						/**		Linked List Operations	   **/
/*
	- Basic linked list operations:
		1. Traversal
		2. Insertion
		3. Deletion
		4. Search
		5. Sort

	
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

//Creating a node
struct Node {
	int data;
	struct Node * next;
};

typedef struct Node node;

void insertAtBeginning(node** head_ref, int new_data){
	node* new_node = (node *)malloc(sizeof(node));
	
	// insert the data
	new_node->data = new_data;
	new_node->next = *head_ref;
	
	// move head to new nod
	*head_ref = new_node;
}

// Insert a node after a node
void insertAfter(node* prev_node, int new_data){
	if(prev_node == NULL){
		cout << "The given previous node cannot be NULL";
		return;
	}
	
	node* new_node = (node*)malloc(sizeof(node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// Insert at the end
void insertAtEnd(node** head_ref, int new_data){
	node* new_node = (node*)malloc(sizeof(node));
	node* last = *head_ref;
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	
	while(last->next != NULL)
		last = last->next;
	
	last->next = new_node;
	return;
}

// Delete a node
void deleteNode(node** head_ref, int key){
	node *tmp = *head_ref, *prev;
	
	if(tmp != NULL && tmp->data == key){
		*head_ref = tmp->next;
		free(tmp);
		return;
	}
	
	//Find the key to be deleted
	while(tmp != NULL && tmp->data != key){
		prev = tmp;
		tmp = tmp->next;
	}
	
	//if the key is not present
	if(tmp == NULL) return;
	
	//Remove the node
	prev->next = tmp->next;
	
	free(tmp);
}

//Search a nod
bool searchNode(node** head_ref, int key){
	node* current= *head_ref;
	
	while(current != NULL){
		if(current->data == key)
			return true;
		current = current->next;
	}
	return false;
}

// Sort the linked list
void sortLinkedList(node** head_ref) {
	node *current = *head_ref, *index = NULL;
	int tmp;
	
	if(head_ref == NULL){
		return;
	}
	else {
		while(current != NULL){
			index = current->next;
			
			while(index != NULL){
				if(current->data > index->data){
					tmp = current->data;
					current->data = index->data;
					index->data = tmp;
				}
				index = index->next;
			}
			
			current = current->next;
		}
	}
}

//print the linked list
void printList(node* p){
	cout << p->data;
	p = p->next;
	while(p != NULL){
		cout << " -->" << p->data;
		p = p->next; 
	}
	cout << endl;
}

int main(){
	node* head = NULL;
	
	insertAtEnd(&head, 1);
	insertAtBeginning(&head, 2);
	insertAtBeginning(&head, 3);
	insertAtEnd(&head, 4);
	insertAfter(head->next, 5);
	
	cout << "Linked list: ";
	printList(head);
	
	cout << "\nAfter deleting an element: ";
	deleteNode(&head, 3);
	printList(head);
	
	int item_to_find = 3;
	if(searchNode(&head, item_to_find)) {
		cout << "\n" << item_to_find << " is found\n";
	}
	else
		cout << "\n" << item_to_find << " is not found\n";
		
	sortLinkedList(&head);
	cout << "\nSorted List: ";
	printList(head);
}
