					/** AVL Tree **/
/*
	- AVL tree is a self-balancing binary search tree in which each node
	maintans extra information called a balance factor whose value either
	-1, 0 or +1.
	
	- Balance factor of a node in an AVL tree is the difference between the
	height of left subtree and that of the right subtree of that node.
		
		Balance Factor = | Height of left subtree - Height of right subtree |
	
	- The self balancing property of an avl tree is maintained by the balance
	factor. The value of balance factor should always be -1, 0 or +1.

	- Operations on an AVL tree:
		1. Rotating the subtrees in an AVl Tree:
			- Left Rotate
			- Right Rotate
			- Left-Right and Right-Left Rotate
			
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

class Node {
	public:
		int key;
		int height;
		Node *left;
		Node *right;
};

int max(int a, int b);

// Calculate height
int height(Node *N){
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b) {
	return (a < b) ? b : a;
}

// New node creation
Node *newNode(int key){
	Node *node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

// Rotate right
Node *rightRotate(Node *y){
	Node *x = y->left;
	Node *T2 = x->right;
	
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	x->height = max(height(y->left), height(x->right)) + 1;
	
	return x;
}

// Rotate left
Node *leftRotate(Node *x){
	Node *y = x->right;
	Node *T2 = y->left;
	
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	
	return y;
}

// Get the balance factor for each node
int getBalanceFactor(Node *N){
	if(N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key){
	if(node == NULL)
		return newNode(key);
	
	if(key < node->key)
		node->left = insertNode(node->left, key);
	else if(key > node->key)
		node->right = insertNode(node->right, key);
	else{
		return node;
	}
	
	node->height = 1 + max(height(node->left), height(node->right));
	
	int balanceFactor = getBalanceFactor(node);
	if(balanceFactor > 1){
		if(key < node->left->key){
			return rightRotate(node);
		} else if(key > node->left->key) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	
	if(balanceFactor < -1){
		if(key > node->right->key){
			return leftRotate(node);
		} else if(key < node->right->key){
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}

// Node with minimum value
Node *nodeWithMinimumValue(Node *node){
	Node *curr = node;
	while(curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

// Delete a node
Node * deleteNode(Node *root, int key){
	// Find the node and delete it
	if(root == NULL)
		return root;
	if(key < root->key)
		root->left = deleteNode(root->left, key);
	else if(key > root->key)
		root->right = deleteNode(root->right, key);
	else{
		if((root->left == NULL) || (root->right == NULL)){
			Node *tmp = root->left ? root->left : root->right;
			if(tmp == NULL) {
				tmp = root;
				root = NULL;
			}
			else *root = *tmp;
			
			free(tmp);
		} else {
			Node *tmp = nodeWithMinimumValue(root->right);
			root->key = tmp->key;
			root->right = deleteNode(root->right, tmp->key);
		}
	}
	
	if(root == NULL)
		return root;
	
	// Upfate the balance factor of each node and balance the tree
	root->height = 1 + max(height(root->left), height(root->right));
	int balanceFactor = getBalanceFactor(root);
	if(balanceFactor > 1){
		if(getBalanceFactor(root->left) >= 0){
			return rightRotate(root);
		} else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
		
	}
	
	if(balanceFactor < -1){
		if(getBalanceFactor(root->right) <= 0){
			return leftRotate(root);
		}
		else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}

// Print the tree
void printTree(Node *root, string indent, bool last){
	if(root != NULL){
		cout << indent;
		if(last) {
			cout << "R---";
			indent += "  ";
		} else {
			cout << "L---";
			indent += "| ";
		}
		cout << root->key << endl;
		printTree(root->left, indent, false);
		printTree(root->right, indent, true);
	}
}

int main(){
	
	Node *root = NULL;
  root = insertNode(root, 33);
  root = insertNode(root, 13);
  root = insertNode(root, 53);
  root = insertNode(root, 9);
  root = insertNode(root, 21);
  root = insertNode(root, 61);
  root = insertNode(root, 8);
  root = insertNode(root, 11);
  printTree(root, "", true);
  root = deleteNode(root, 13);
  cout << "After deleting " << endl;
  printTree(root, "", true);
	
	return 0;
}
