					/** Binary Tree **/
/*
	- A binary tree is a tree data structure in which each parent node can have 
	at most two children. Each node of a binary tree consists of three items:
		1. data item
		2. address of left child
		3. address of right child
	
	- Types of Binary Tree:
		1. Full Binary Tree
		2. Perfect Binary Tree
		3. Complete Binary Tree
		4. Degenerate or Pathological Tree
		5. Skewed Binary Tree
		6. Balanced Binary Tree
		
	- Binary Tree Applicatios
		1. For easy and quick access to data
		2. In router algorithms
		3. To implement heap data structure
		4. Syntax Tree
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

// new node creation
struct node *newNode(int data){
	struct node *node = (struct node *)malloc(sizeof(struct node));
	
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// Traverse Preorder
void traversePreOrder(node* tmp){
	if(tmp != NULL){
		cout << " " << tmp->data;
		traversePreOrder(tmp->left);
		traversePreOrder(tmp->right);
	}
}

// Traverse Inorder
void traverseInOrder(struct node* temp){
	if(temp != NULL){
		traverseInOrder(temp->left);
		cout << " " << temp->data;
		traverseInOrder(temp->right);
	}
}

// Traverse Postorder
void traversePostOrder(struct node *temp){
	if(temp!= NULL){
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout << " " << temp->data;
	}
}

int main() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);

  cout << "preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);
}

