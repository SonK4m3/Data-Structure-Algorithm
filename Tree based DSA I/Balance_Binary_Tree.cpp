					/** Balance Binary Tree **/
/*
	- A balanced binary tree in which the height of the left and right subtree of any 
	node differ by not more than 1.
	
	- The conditions for a height-balanced binary tree:
		1. Difference between the left and the right subtree for any node is not more
		than one.
		2. the left subtree is balanced
		3. the right subtree is balanced
	
	- df = [height of left child - height of right child]

*/					
#include<iostream>
#include<cmath>
using namespace std;

#define bool int

class node {
	 public:
	 	int item;
	 	node *left;
	 	node *right;
};

// Create a new node
node *newNode(int item) {
	node *Node = new node();
	Node->item = item;
	Node->left = Node->right = NULL;
	
	return Node;
}

// check height balance
bool checkHeightBalance(node *root, int *height){
	int leftHeight = 0, rightHeight = 0;
	
	int l = 0, r = 0;
	
	if (root == NULL) {
		*height = 0;
		return 1;
	}
	
	l = checkHeightBalance(root->left, &leftHeight);
	r = checkHeightBalance(root->right, &rightHeight);
	
	*height = (leftHeight > rightHeight ? leftHeight : rightHeight);
	
	if(abs(leftHeight - rightHeight) >= 2)
		return 0;
	else 
		return l && r;
}

int main(){
	int height = 0;
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	if(checkHeightBalance(root, &height))
		cout << "The tree is balanced";
	else 
		cout << "The tree is not balanced";
}

