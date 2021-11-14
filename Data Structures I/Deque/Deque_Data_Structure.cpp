					/**		Deque Data Structure	**/
/*
	- Deque or Double Ended Queue is a type of queue in which insertion and
	removal of elements can either be performed from the front or the rear.
	Thus, it does not follow FIFO rule.
	
	- Operations on a Deque
		1. insert at the Front
		2. insert at the Rear
		3. delete from the Front
		4. delete from the Rear
		5. check empty
		6. check full
*/
#include<iostream>
using namespace std;

#define MAX 10

class Deque {
	int arr[MAX];
	int front, rear, size;
	
	 public:
	Deque(int size){
		front = rear = -1;
		this->size = size;
	}
	
	void insertfront(int key);
	void insertrear(int key);
	void deletefront();
	void deleterear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();
	void printDeque();
};

bool Deque::isFull() {
	return ( (front == 0 && rear == size - 1) || front == rear + 1); 
}

bool Deque::isEmpty(){
	return front == -1;
}

void Deque::insertfront(int key){
	if(isFull()){
		cout << "Overflow\n"
			<< endl;
		return;
	}
	cout << "insert front element: " << key << endl; 
	
	if(front == -1){
		front = 0;
		rear = 0;
	}
	
	else if (front == 0){
		front = size - 1;
	}
	else
		front = front - 1;
		
	arr[front] = key;
}

void Deque::insertrear(int key){
	if (isFull()){
		cout << "Overflow\n" << endl;
		return;
	}
	
	cout << "insert rear element: " << key << endl;
	
	if(front == -1){
		front = 0;
		rear = 0;
	}
	
	else if(rear == size - 1)
		rear = 0;
	else
		rear = rear + 1;
		
	arr[rear] = key;
}

void Deque::deletefront(){
	if (isEmpty()){
		cout << "Queue UnderFlow\n" << endl;
		return;
	}
	
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if(front == size - 1)
		front = 0;
	else
		front = front + 1;
}

void Deque::deleterear(){
	if (isEmpty()){
		cout << "Queue Underflow\n" << endl;
		return;
	}
	
	if(front == rear){
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
		rear = size - 1;
	else rear = rear - 1;
}

int Deque::getFront(){
	if(isEmpty()){
		cout << "Underflow\n" << endl;
		return -1;
	}
	return arr[front];
}

int Deque::getRear(){
	if(isEmpty()){
		cout << "Underflow\n" << endl;
		return -1;
	}
	return arr[rear];
}

int main(){
	Deque dq(4);
	
	dq.insertfront(5);
	dq.insertrear(11);
	
	cout << "rear element: " << dq.getRear() << endl;
	
	dq.deleterear();
	cout << "after deletion of the rear element, the new rear element: " << dq.getRear() << endl;
		
	dq.insertfront(8);
	
	cout << "front element: " << dq.getFront() << endl;
	
	dq.deletefront();
	cout << "after deletion of front element new front element: " << dq.getFront() << endl;	 
}
	
