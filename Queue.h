/*Alexandria Piatt
ampiatt@mail.umkc.edu
12/11/16*/

#pragma once
#include<iostream>
using namespace std;


class Node
{
public:
	Node() { next = NULL; }
	Node(int theData, Node* Link) { data = theData; next = Link; }
	int data;
	Node* next;
};



class Queue
{
public:
	Queue();
	int size() const;
	void push(const int& item);
	void pushToTop(const int& item);
	int pop();
	bool is_empty() const;
	void empty();
	//Returns the oldest (top) element
	int top() const;
	void print();
private:
	Node *Head;
	Node *Tail;
	int count;
};
