					/** Adjacency Matrix **/
/*
	- An adjacency matrix is a way of representing a graph as a matrix of booleans.
	A finite graph can be represented in the form of a square matrix on computer, 
	where the boolean value of the matrix indicates if there is a direct path between
	two vertices.
	
	- Pros of Adjacency Matrix:	
		The basic operations like adding an edge, removing an edge, and checking
		whether there is an edge from vertex i to vertex j are extremely time efficient, 
		constant time operations.
	
	- Cons of Adjacency Matrix:
		The VxV space requirement of the adjacency matrix makes it a memory 
		hog. Graphs out in the wild usually don't have too many connections 
		and this is the major reason why adjacency lists are the better choice 
		for most tasks.	
	
	- Adjacency Application:
		1. Creating routing table in networks
		2. Navigation tasks
*/
// Adjacency Matrix presentation in C++
#include<iostream>
using namespace std;

class Graph {
	private:
		bool** adjMatrix;
		int numVertices;
		
	public:
		// Initialize the matrix to zero
		Graph(int numVertices){
			this->numVertices = numVertices;
			adjMatrix = new bool*[numVertices];
			for(int i = 0; i < numVertices; i++) {
				adjMatrix[i] = new bool[numVertices];
				for(int j = 0; j < numVertices; j++)
					adjMatrix[i][j] = false;
			}
		}
		
		// Add edges
		void addEdge(int i, int j){
			adjMatrix[i][j] = true;
			adjMatrix[j][i] = true;
		}
		
		// Remove edges
		void removeEdge(int i, int j){
			adjMatrix[i][j] = adjMatrix[j][i] = false;
		}
		
		// Print the matrix
		void toString() {
			for(int i = 0; i < numVertices; i++) {
				cout << i << " : ";
				for(int j = 0; j < numVertices; j++)
					cout << adjMatrix[i][j] << " ";
				cout << endl;
			}
		}
		
		~Graph() {
			for(int i = 0; i < numVertices; i++)
				delete[] adjMatrix[i];
			delete[] adjMatrix;
		}
};

int main(){
	Graph g(4);
	g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.toString();
  	
  	return 0;
}
