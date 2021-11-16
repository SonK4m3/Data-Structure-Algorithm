					/** 	Heap Data Structure		**/
/*
	- Heap data structure is a complete binary tree that satisfies the heap property, 
	where any given node is:
		1. always greater than its child nodes and the key of the node is the largest 
		among all other nodes. This property is also called max heap property.
		2. always smaller than the child node and the key of the root node is the smallest
		among all other nodes. This property is also called min heap property.
	
	- also called a binary heap
	- Heap Operations:
		Heapify
		Insert Element into Heap
		Delete Element from Heap
		Peek
		Extract-Max/Min
	
	- Applications:
		1. Heap is used while implementing a priority queue.
		2. Dijkstra's Algorithm.
		3. Heap Sort.
*/
#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void heapify(vector<int> &hT, int i){
	int size = hT.size();
	int largest = i;
	int l = 2 * i + 1, r = 2 * i + 2;
	
	if(l < size && hT[l] > hT[largest])
		largest = l;
	if(r < size && hT[r] > hT[largest])
		largest = r;
	
	if(largest != i) {
		swap(&hT[i], &hT[largest]);
		heapify(hT, largest);
	}	
}

void insert(vector<int> &hT, int newNum){
	int size = hT.size();
	if(size == 0){
		hT.push_back(newNum);
	}
	else {
		hT.push_back(newNum);
		for(int i = size / 2 - 1; i >= 0; i--)
			heapify(hT, i);
	}
}

void deleteNode(vector<int> &hT, int num){
	int size = hT.size();
	int i;
	for(i = 0; i < size; i ++){
		if(num == hT[i])
			break;
	}
	swap(&hT[i], &hT[size - 1]);
	
	hT.pop_back();
	for(int i = size / 2 - 1; i >= 0; i--)
		heapify(hT, i);
}

void printArray(vector<int> &hT){
	for(int i = 0; i < hT.size(); i++)
		cout << hT[i] << " ";
	cout << endl;
}

int main(){
	vector<int> heapTree;
	
	insert(heapTree, 3);	
	insert(heapTree, 4);
	insert(heapTree, 9);
	insert(heapTree, 5);
	insert(heapTree, 2);
	
	cout << "Max-Heap array: ";
	printArray(heapTree);
	
	deleteNode(heapTree, 4);
	
	cout << "After deleting an elemnet: ";
	
	printArray(heapTree);
}
