				/**		Complete Binary Tree	**/
/* 
	- A complete binary tree is a binary tree in which all the levels
	are completely filled except possibly the lowest one, which is filled
	from the left.
	
	- A complete binary tree is just like a full binary tree, 
	but with two major differences:  
		1. All the leaf elements must lean towards the left.
		2. The last leaf element might not have a right sibling i.e.
			a complete binary tree doesn't have to be a full binary
			tree.
	
	- Relation between child and parent node: 
		element i-th has 2 child's index are 2i + 1 and 2i + 2.
		element i-th has parent's index is (i - 1)/2.
	- Application:
		1. Heap-based data structure.
		2. Heap sort.
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Node {
	int key;
	struct Node *left, *right;
}Node;

// Create node
struct Node *newNode(char k) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->key = k;
	node->right = node->left = NULL;
	return node; 
} 

// Count the number of nodes
int countNumNodes(Node *root) {
	if(root == NULL)
		return (0);
	return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the tree is a complete binary tree
bool checkComplete(Node *root, int index, int numberNodes) {
	if(root == NULL)
		return true;
	
	if(index >= numberNodes)
		return false;
	
	return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main(){
	Node *root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	
	int node_count = countNumNodes(root);
	int index = 0;
	
	if(checkComplete(root, index, node_count))
		cout << "The tree is a complete binary tree\n";
	else
		cout << "The tree is not a complete binary tree\n";
	
	return 0;
}
