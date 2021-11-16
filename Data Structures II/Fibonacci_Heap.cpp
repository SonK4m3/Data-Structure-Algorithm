						/**		Fibonacci Heap	 **/
/*
	- A fibonacci heap os a data structure that consists of a collection 
	of trees which follow min heap or max heap property. 
	- In a fibonacci heap, a node can have more than two children of no
	children at all. Also it has more efficient heap operations than that
	supported by the binomial and binary heaps.
	
	- The fibonacci heap is called a fibonacci heap because the trees are
	constructed in a way such that a tree of order n has at least F(n+2) 
	nodes in it, where F(n+2) is the (n+2)-th Fibonacci number.
	
	- Properties of a Fibonacci Heap
		1. It is a set of min heap-ordered trees.(the parent is always
		smaller than the children.)
		2. A pointer is maintained at the minimum element node.
		3. It consists of a set of marked nodes.(Decrease key operation)
		4. The trees within a Fibonacci heap are unordered but rooted.
	
	- The roots of all the trees are linked together for faster access. The
	child nodes of a parent node are connected to each other through a circular
	doubly linked list.
		1. Deleting a node from the tree takes O(1) time.
		2. The concatenation of two such lists takes O(1) time.	
	
	- Operations on a Fibonacci Heap
									Complexities
		1. Insertion				O(1)
		2. Find min					O(1)
		3. Union					O(1)
		4. Extract Min				O(log n)
		5. Decrease Key				O(1)
		6. Delete Node				O(log n)
	
	- Application
		1. To improve the asymptotic running time of Dijkstra's algorithm
*/

// Code in Decrease Key and Delete Node Operations 
