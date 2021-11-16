							/**		Hash Table	  **/
/*
	- The Hash table data structure stores elements in key-value pairs where
		1. Key - unique integer that is used for indexing the values.
		2. data that are associated with key.
		
	- Hashing (Hash Function)
		In a hash table, a new index is processed using the keys.
		And, the element corresponding to that key is stored in
		the index. This process is called hashing.
	
	- Hash Collision
		When the has function generates the same index for multiple keys, 
		there will be a conflict(what value to be stored in that index).
		This is called a hash collision. 
		
		We can resolve the hash collision using one of the following techniques:
			1. Collision resolution by chaining
			2. Open Addresing: Linear/ Quadratic Probing and Double Hashing

	- Applictions:
		1. constant time lookup and insertion is required
		2. cryptographic applications
		3. indexing data is required
*/
#include<iostream>
#include<list>
using namespace std;

class HashTable {
	int capacity;
	list<int> *table;
	
	 public:
	HashTable(int V);
	void insertItem(int key, int data);
	void deleteItem(int key);
	
	int checkPrime(int n){
		int i;
		if(n == 1 || n == 0)
			return 0;
		for(int i = 2; i * i <= n; i++)
			if(n % i == 0)
				return 0;
		return 1;
	}
	
	int getPrime(int n){
		if(n % 2 == 0)
			n++;
		while(!checkPrime(n))
			n+= 2;
		return n;
	}
	
	int hashFunction(int key){
		return key % capacity;
	}
	
	void displayHash();
};

HashTable::HashTable(int c){
	int size = getPrime(c);
	this->capacity = c;
	table = new list<int>[capacity];
}

void HashTable::insertItem(int key, int data){
	int index = hashFunction(key);
	table[index].push_back(data);
}

void HashTable::deleteItem(int key){
	int index = hashFunction(key);
	
	list<int>:: iterator i;
	for(i = table[index].begin(); i != table[index].end(); i++){
		if(*i == key)
			break;
	}
	
	if(i != table[index].end())
		table[index].erase(i);
}

void HashTable::displayHash(){
	for(int i = 0; i < capacity; i++){
		cout << "Table[" << i << "]";
		list<int> :: iterator j;
		for(j = table[i].begin(); j != table[i].end(); j++)
			cout << " -->" << *j;
		cout << endl;
	}
}

int main(){
	int key[] = {231, 321, 212, 321, 433, 262};
	int data[] = {123, 432, 523, 43, 423, 111};
	int size = sizeof(key) / sizeof(key[0]);
	
	HashTable h(size);
	
	for(int i = 0; i < size; i++)
		h.insertItem(key[i], data[i]);
	
	h.displayHash();
	
	h.deleteItem(123);
	cout << "After deleted item 123: \n";
	h.displayHash();
	
}
