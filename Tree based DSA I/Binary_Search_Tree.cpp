					/** Binary Search Tree **/
/*
	- The properties that separate a binary search tree from a regular 
	binary tree is:
		1. All nodes of left subtree are less than the root node
		2. All nodes of right subtree are more than the root node
		3. Both subtrees of each node are also BSTs i.e. they have the
		above two properties.

	- Operation:
		1. Search
		2. Insert
		3. Delete
	
	- Binary Search Tree Applications:
		1. In multilevel indexing in the database
		2. For dynamic sorting
		3. For managing virtual memory areas in Unix kernel
*/	
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};		

// Create a node
struct Node *newNode(int item){
	struct Node *tmp = new Node;
	tmp->key = item;
	tmp->left = tmp->right = NULL;
	return tmp;
}

// Inorder Traversal
void inorder(struct Node *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

//Print Tree
void printNode(struct Node *root, string indent, bool last){
	if(root != NULL){
		cout << indent;
		if(last){
			cout << "R---";
			indent += "  ";
		}
		else {
			cout << "L---";
			indent += "| ";
		}
		cout << root->key << endl;
		printNode(root->left, indent, false);
		printNode(root->right, indent, true);
	}
}

// Insert a node
struct Node *insert(struct Node *node, int key){
	if(node == NULL) return newNode(key);
	
	if(key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	
	return node;
}

// Find the inorder successor
struct Node *minValueNode(struct Node *node){
	struct Node *curr = node;
	
	while(curr && curr->left != NULL)
		curr = curr->left;
	
	return curr;
}

// Deleting a node
struct Node *deleteNode(struct Node *root, int key){
	if(root == NULL)
		return root;
	
	if(key < root->key)
		root->left = deleteNode(root->left, key);
	else if(key > root->key)
		root->right = deleteNode(root->right, key);
	else{
		if(root->left == NULL){
			struct Node *tmp = root->right;
			free(root);
			return tmp;
		} else if(root->right == NULL){
			struct Node *tmp = root->left;
			free(root);
			return tmp;
		}
		struct Node *tmp = minValueNode(root->right);
	
		root->key = tmp->key;
		root->right = deleteNode(root->right, tmp->key);
	}
	return root;
}

int main(){
	struct Node *root = NULL;
	  root = insert(root, 8);
	  root = insert(root, 3);
	  root = insert(root, 1);
	  root = insert(root, 6);
	  root = insert(root, 7);
	  root = insert(root, 10);
	  root = insert(root, 14);
	  root = insert(root, 4);
	
	  cout << "Inorder traversal: \n";
	  inorder(root);
	  cout << endl;
	  printNode(root, "", true);
	
	  cout << "\nAfter deleting 10\n";
	  root = deleteNode(root, 10);
	  cout << "Inorder traversal: \n";
	  inorder(root);
	  cout << endl;
	  printNode(root, "", true);
	
	return 0;
}

