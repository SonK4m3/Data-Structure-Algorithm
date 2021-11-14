					/** Heap Sort Algorithm **/
/*
	Working of Heap Sort
		1. Since the tree satisfies Max-Heap property, then the largest items
		is stored at the root node.
		2. Swap: Remove the root element and put at the end of the array. Put 
		the last item of the tree at the vacant place.
		3.Remove: Reduce the size of the heap by 1.
		4. Heapify: Heapify the root element again so tha we have the hightest
		element at root.
		5. The process is repeated until all the items of the list are sorted.
		
	Time Complexity
		Best				O(nlog n)
		Worst				O(nlog n)
		Average				O(nlog n)
		Space Complexity	O(1)
		Stability			No
*/
#include<iostream>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int arr[], int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if(l < n && arr[l] > arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])	
		largest = r;
	
	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	//Build max heap
	for(int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	
	// heap sort
	for(int i = n - 1; i >= 0; i--){
		swap(arr[0], arr[i]);
		
		heapify(arr, i, 0);
	} 
}

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
	int arr[] = {1, 12, 9, 5, 6, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	
	cout << "Sorted array is \n";
	printArray(arr, n);
}
