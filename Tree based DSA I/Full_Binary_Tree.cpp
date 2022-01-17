					/** Full Binary Tree **/
/* 
	- A full Binary tree is a special type of binary tree in which every parent node
	has either two or no children.
	
	- It is also known as a proper binary tree.
	
	- Full Binary Tree Theorems
		Let, i = the number of internal nodes
			 n = be the total number of nodes
			 l = number of leaves
			 r = number of levels
		
		1. The number of leaves is i + 1
		2. The total number of nodes is 2i + 1
		3. The number of internal nodes is (n - 1)/2
		4. The number of leaves is (n + 1)/2
		5. The total number of nodes is 2l - 1
		6. The number of internal nodes is l - 1
		7. The number of leaves is at most 2^(r - 1)

*/
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

// New node creation
struct Node *newNode(char k){
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

bool isFullBinaryTree(struct Node *root){
	if(root == NULL)
		return true;
	
	if(root->left == NULL && root->right == NULL)
		return true;
	
	if((root->left) && (root->right))
		return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
	
	return false;
}

int main(){
	struct Node *root = NULL;
	root = newNode(1);
 	root->left = newNode(2);
 	root->right = newNode(3);
  	root->left->left = newNode(4);
  	root->left->right = newNode(5);
  	root->left->right->left = newNode(6);
  	root->left->right->right = newNode(7);

  	if (isFullBinaryTree(root))
    	cout << "The tree is a full binary tree\n";
  	else
    	cout << "The tree is not a full binary tree\n";

	return 0;
}
