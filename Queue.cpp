#include "Queue.h"

//default constructor
template <class T>
Queue<T>::Queue()
{
	Head = Tail = NULL;
	count = 0;
}

//return the size of the queue
template <class T>
int Queue<T>::size() const
{
	return count;
}

//check if queue is empty
template <class T>
bool Queue<T>::is_empty() const
{
	return (Head == NULL);
}
//add elements to the queue
template <class T>
void Queue<T>::push(T& item)
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

//remove an element from queue
template <class T>
T Queue<T>::pop()
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
template <class T>
void Queue<T>::empty()
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
template <class T>
T Queue<T>::top() const
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
template <class T>
void Queue<T>::print()
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


