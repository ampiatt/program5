#pragma once
#include<iostream>
#include "Patient.h"
using namespace std;


template <class T> class Node
{
public:
	Node() { next = NULL; }
	Node(T theData, Node <T>* Link) { data = theData; next = Link; }
	T data;
	Node<T> *next;
};



template <class T> class Queue
{
public:
	Queue();
	int size() const;
	void push(const T & item);
	T pop();
	bool is_empty() const;
	void empty();
	//Returns the oldest (top) element
	T top() const;
	void print();
private:
	Node <T> *Head;
	Node <T> *Tail;
	int count;
};
