					/** B-tree **/
/*
	- B-tree is a special tyoe of self-balancing search tree in 
	which each node can contain more than one key and can have 
	more than two children. It is a generalized form of the 
	binary search tree.
	
	- It is also known as a height-balanced m-way tree.
	
	- B-tree Properties:
		1.For each node x, the keys are stored in increasing order.
		2.In each node, there is a boolean value x.leaf which is true
		if x is a leaf.
		3.If n is the order of the tree, each internal node can contain
		at most n - 1 keys along with a pointer to each child.
		4. Each node except root can have at most n children and
		at least n/2 children.
		5. All leaves have the same depth.
		6.The root has at least 2 children and contains a minimum of 1 key.
		7.If n >= 1, then for any n-key B-tree of height and minimum degree
		t >= 2, h >= log(t)((n+1)/2).
		
	- Operations on a B-tree
		1. Searching
		2. Insertion
		3. Deletion


*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
	int *keys;
	int t;
	TreeNode **C;
	int n;
	bool leaf;
	
	 public:
	TreeNode(int tmp, bool bool_leaf);
	
	void insertNonFull(int k);
	void splitChild(int i, TreeNode *y);
	void traverse();
	
	TreeNode  *search(int k);
	
	friend class BTree;
};

class BTree {
	TreeNode *root;
	int t;
	 public:
	BTree(int tmp){
		root = NULL;
		t = tmp;
	}
	
	void traverse() {
		if(root != NULL)
			root->traverse();
	}
	
	TreeNode *search(int k) {
		return (root == NULL) ? NULL : root->search(k);
	}
	
	void insert(int k);
};

TreeNode::TreeNode(int t1, bool leaf1) {
	t = t1;
	leaf = leaf1;
	
	keys = new int[2 * t - 1];
	C = new TreeNode *[2 * t];
	
	n = 0;
}

void TreeNode::traverse() {
	int i;
	for(i = 0; i < n; i++) {
		if(leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}
	
	if(leaf == false)
		C[i]->traverse();
}

TreeNode *TreeNode::search(int k) {
	int i = 0;
	while(i < n && k > keys[i])
		i ++;
	
	if(keys[i] == k)
		return this;
	
	if(leaf == true)
		return NULL;
		
	return C[i]->search(k);
}

void BTree::insert(int k){
	if(root == NULL){
		root = new TreeNode(t, true);
		root->keys[0] = k;
		root->n = 1;
	} else {
		if(root->n == 2 * t - 1) {
			TreeNode *s = new TreeNode(t, false);
			
			s->C[0] == root;
			
			s->splitChild(0, root);
			
			int i = 0;
			if(s->keys[0] < k)
				i ++;
			s->C[i]->insertNonFull(k);
			
			root = s;
		} else
			root->insertNonFull(k);
	}
}

void TreeNode::insertNonFull(int k){
	int i = n - 1;
	
	if(leaf == true) {
		while(i >= 0 && keys[i] > k) {
			keys[i + 1] = keys[i];
			i--;
		}
		
		keys[i + 1] = k;
		n = n + 1;
	} else {
		while(i >= 0 && keys[i] > k)
			i --;
		
		if(C[i + 1]->n == 2 * t - 1) {
			splitChild(i + 1, C[i + 1]);
			
			if(keys[i + 1] < k)
				i ++;
		}
		C[i + 1]->insertNonFull(k);
	}
}

void TreeNode::splitChild(int i, TreeNode *y) {
	TreeNode *z = new TreeNode(y->t, y->leaf);
	z->n = t - 1;
	
	for(int j = 0; j < t - 1; j ++) {
		z->keys[j] = y->keys[j + t];
	}
	
	if(y->leaf == false) {
		for(int j = 0; j < t; j ++)
			z->C[j] = y->C[j + t];
	}
	
	y->n = t - 1;
	for(int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];
	
	C[i + 1] = z;
	
	for(int j = n - 1; j >= i; j--)
		keys[i + 1] = keys[j];
	
	keys[i] = y->keys[t - 1];
	n += 1;
}

int main(){
	BTree t(3);
	t.insert(8);
	t.insert(9);
	t.insert(10);
	t.insert(11);
  	t.insert(15);
  	t.insert(16);
  	t.insert(17);
  	t.insert(18);
  	t.insert(20);
  	t.insert(23);
  	
  	cout << "The B-Tree is: ";
  	t.traverse();
  	
  	int k = 10;
  	(t.search(k) != NULL) ? cout << endl
  					<< k << " is found" 
  					: cout << endl 
  					 << k << "is not Found";
  					 
  	k = 2;
  	(t.search(k) != NULL) ? cout << endl
  					<< k << " is found"
  					: cout << endl
  					<< k << " is not Found\n";
	return 0;
}
