#ifndef H_QUEUE
#define H_QUEUE

#include <iostream>

using namespace std;

class Node {
public:
	Node() { next = NULL; }
	Node(int nData, Node *Link) { data = data; next = Link; }
	int data;
	Node* next;

};
class Queue {
public:
public:
	Queue();
	int size() const;
	void push(const int& item);
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

#endif 

