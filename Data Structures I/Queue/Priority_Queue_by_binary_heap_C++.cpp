					/**		Priority Queue		**/
/*
	A priority queue is a special type of queue in which each element is 
	associated with a priority value. And, elements are served on the basis
	of their priority. That is, higher priority elements are served first.
	
	- A comarative analysis of different implementations of priority queue:
	Operations				peek		insert		delete
	Linked List				O(1)		O(n)		O(1)
	Binary Heap				O(1)		O(log n)	O(log n)
	Binary Search Tree		O(1)		O(log n)	O(log n)

	- Priority Queue Operations
		1. Insert
		2. Delete
		3. Peek
		4.	Extract-Max/Min
		
	- Applications:
		1. Dijkstra's Algorithm
		2. for implementing stack
		3. for load balancing and interrupt handling in
		an operating system
		4. for data compression in Huffman code	
*/
#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(vector<int> &hT, int i){
	int size = hT.size();
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if(l < size && hT[l] > hT[largest])
		largest = l;
	if(r < size && hT[r] > hT[largest])
		largest = r;
		
	if(largest != i){
		swap(&hT[i], &hT[largest]);
		heapify(hT, largest);
	}
}

void insert(vector<int> &hT, int newNum){
	int size = hT.size();
	if(size == 0)
		hT.push_back(newNum);
	else {
		hT.push_back(newNum);
		for(int i = size / 2 - 1; i >= 0; i--)
			heapify(hT, i);
	}
}

void deleteNode(vector<int> &hT, int num){
	int size = hT.size();
	int i;
	for(i = 0; i < size; i++){
		if(num == hT[i])
			break;
	}
	swap(&hT[i], &hT[size - 1]);
	
	hT.pop_back();
	for(int i = size / 2 - 1; i >= 0; i--)
		heapify(hT, i);
}

void printArray(vector<int> hT){
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
	
	cout << "After deleting an element: ";
	printArray(heapTree);

}
