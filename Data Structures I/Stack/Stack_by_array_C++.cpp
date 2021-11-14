#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX 10

int size = 0;

struct stack{
	int item[MAX];
	int top;
};

typedef struct stack st;

void creatEmptyStack(st *s){
	s->top = -1;
}

int isFull(st *s){
	return s->top == MAX - 1;
}

int isEmpty(st *s){
	return s->top == -1;
}

void push(st *s, int newitem){
	if(isFull(s))
		cout << "STACK FULL";
	else{
		s->top ++;
		s->item[s->top] = newitem;
	}
	size ++;
}

void pop(st *s){
	if(isEmpty(s))
		cout <<"\n STACK EMPTY \n";
	else{
		cout << "Item popped= " << s->item[s->top];
		s->top --;
	}
	size --;
	cout << endl;
}

void printStack(st *s){
	cout << "STACK: ";
	for(int i = 0; i < size; i++)
		cout << s->item[i] <<" ";
	cout << endl;
}

int main(){
	int ch;
	st *s = (st *)malloc(sizeof(st));
	
	creatEmptyStack(s);
	
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	
	printStack(s);
	
	pop(s);
	
	cout << "\nAfer popped\n";
	printStack(s);
}
