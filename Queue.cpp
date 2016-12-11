/*Alexandria Piatt
ampiatt@mail.umkc.edu
12/11/16*/

#include "Queue.h"

//default constructor

Queue::Queue()
{
	Head = Tail = NULL;
	count = 0;
}

//return the size of the queue
int Queue::size() const
{
	return count;
}

//check if queue is empty
bool Queue::is_empty() const
{
	return (Head == NULL);
}
//add elements to the queue
void Queue::push(const int& item)
{
	if (is_empty())
	{
		Head = new Node(item, NULL);
		Tail = Head;
		count++;
	}
	else
	{
		Tail->next = new Node(item, NULL);
		Tail = Tail->next;
		count++;
	}
}
void Queue::pushToTop(const int& item) {
	if (is_empty()) {
		Head = new Node(item, NULL);
		Tail = Head;
		count++;
	}
	else {
		Node *temp = new Node(item, NULL);
		Head->next = Head;
		Head = temp;

	}
}

//remove an element from queue
int Queue::pop()
{
	if (is_empty())
	{
		cout << "Queue is Empty\n";
		exit(1);
	}
	else
	{
		Node *p;
		int item;
		p = Head;
		item = Head->data;
		Head = Head->next;
		if (Head == NULL)
		{
			Tail = NULL;
		}
		delete p;
		count--;
		return item;
	}

}



//clear the queue
void Queue::empty()
{
	Node* temp;
	while (Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		delete temp;

	}
	Tail = NULL;
	count = 0;
}

//print the first item
int Queue::top() const
{
	if (is_empty())
	{
		cout << "Queue is empty\n";
	}
	else
	{
		return Head->data;
	}
}


//Print all the queue
void Queue::print()
{
	if (is_empty())
	{
		cout << "Queue is Empty\n";
	}
	else
	{
		Node* t = Head;
		while (t != NULL)
		{
			int temp;
			temp = t->data;
			cout << temp << endl;
			t = t->next;
		}
		delete t;
	}
}


