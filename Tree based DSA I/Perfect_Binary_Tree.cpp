					/** Perfect Binary Tree **/
/*
	- A perfect binary tree is a type of binary tree in which every internal node has
	exactly two child nodes and all the leaf nodes are at the same level.
	
	- Recursively, a perfect binary tree can be defined as:
		1. If a single node has no children, it is a perfect binary tree of height h = 0
		2. If a node has h > 0, it is a perfect binary tree if both of its subtrees are
		of height h - 1 and are non-overlapping.
		
	- Perfect Binary Tree Theorems
		1. A perfect binary tree of height h has 2^(h + 1) - 1 node
		2. A perfect binary tree with nodes has height log(n + 1) - 1 = O(ln(n))
		3. A perfect binary tree of height h has 2^h leaf nodes
		4. The average depth of a node in a perfect binary tree is O(ln(n))

*/
#include<iostream>
using namespace std;

struct Node {
	int key;
	struct Node *left;
	struct Node *right;
};

int depth(Node *node){
	int d = 0;
	while(node != NULL){
		d++;
		node = node->left;
	}
	return d;
}

bool isPerfectR(struct Node *root, int d, int level = 0){
	if(root == NULL)
		return true;
	
	if(root->left == NULL && root->right == NULL)
		return (d == level + 1);
	
	if(root->left == NULL || root->right == NULL)
		return false;
		
	return isPerfectR(root->left, d, level + 1) && isPerfectR(root->right, d, level + 1);
}

bool isPerfect(Node *root) {
	int d = depth(root);
	return isPerfectR(root, d);
}

struct Node *newNode(int k){
	struct Node *node = new Node;
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

int main(){
	struct Node *root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	
	if (isPerfect(root))
	   cout << "The tree is a perfect binary tree\n";
	else
	   cout << "The tree is not a perfect binary tree\n";
}
