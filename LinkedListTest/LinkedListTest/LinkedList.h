#pragma once

#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{

private:
	class Node
	{
		friend class LinkedList<T>;
	private:
		T data;
		Node* next;
	public:
		Node(T d, Node* n = NULL) : data(d), next(n) {}
	};

	Node* head;  // Beginning of list
	Node* tail;  // End of list
	int count;      // Number of nodes in list

public:

	LinkedList(const LinkedList<T>& src);  // Copy constructor
	~LinkedList();  // Destructor

	// Default constructor
	LinkedList() : head(NULL), tail(NULL), count(0) {}

	// Returns a reference to first element
	T& front() {
		assert(head != NULL);
		return head->data;
	}

	// Returns a reference to last element
	T& back() {
		assert(tail != NULL);
		return tail->data;
	}

	T& operator[](int pos);

	// Returns count of elements of list
	int size() {
		return count;
	}

	// Returns whether or not list contains any elements
	bool empty() {
		return count == 0;
	}

	void push_front(T value);  // Insert element at beginning
	void push_back(T value);   // Insert element at end
	void insert(int pos, T value); //Insert element at middle position
	void pop_front();    // Remove element from beginning
	void pop_back();     // Remove element from end
	void reverse();      // Reverse list elements

	void dump();  // Output contents of list	
};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& src) :
head(NULL), tail(NULL), count(0)
{
	Node* current = src.head;
	while (current != NULL)
	{
		this->push_back(current->data);
		current = current->next;
	}

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while (!this->empty())
	{
		this->pop_front();
	}
}

template <typename T>
T& LinkedList<T>::operator[](int pos)
{
	assert(head != NULL);

	if (pos >= count - 1)
		return tail->data;
	else
	{
		Node* current = head;
		for (int i = 0; i < pos; i++)
		{
			current = current->next;
		}
		return current->data;
	}
}

template <typename T>
void LinkedList<T>::push_front(T value)
{
	Node* new_head = new Node(value, head);

	if (this->empty())
	{
		head = new_head;
		tail = new_head;
	}
	else
	{
		head = new_head;
	}
	count++;
}

template <typename T>
void LinkedList<T>::push_back(T value)
{
	Node* new_tail = new Node(value, NULL);

	if (this->empty())
	{
		head = new_tail;
	}
	else
	{
		tail->next = new_tail;
	}

	tail = new_tail;
	count++;
}

template <typename T>
void LinkedList<T>::insert(int pos, T value)
{
	if (pos == 0)
		push_front(value);
	else if (pos >= count)
		push_back(value);
	else
	{
		Node* new_node = new Node(value, NULL);
		Node* iter = head;
		for (int i = 0; i < pos - 1; i++)
		{
			iter = iter->next;
		}
		new_node->next = iter->next;
		iter->next = new_node;
	}
}

template <typename T>
void LinkedList<T>::pop_front() {

	assert(head != NULL);

	Node* old_head = head;

	if (this->size() == 1) {
		head = NULL;
		tail = NULL;
	}
	else {
		head = head->next;
	}

	delete old_head;
	count--;
}

template <typename T>
void LinkedList<T>::pop_back() {

	assert(tail != NULL);

	Node* old_tail = tail;

	if (this->size() == 1) {
		head = NULL;
		tail = NULL;
	}
	else {

		// Traverse the list to node just before tail
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}

		// Unlink and reposition
		current->next = NULL;
		tail = current;
	}

	delete old_tail;
	count--;
}


template <typename T>
void LinkedList<T>::reverse()
{
	if (empty())
		return;

	tail = head;
	Node* current = head->next;
	Node* reverse_head = head;
	reverse_head->next = NULL;

	while (current != NULL)
	{
		Node* temp_head = current;
		current = current->next;

		temp_head->next = reverse_head;
		reverse_head = temp_head;
	}

	head = reverse_head;
}

template <typename T>
void LinkedList<T>::dump()
{
	cout << "(";

	Node* current = head;

	if (current != NULL) {

		while (current->next != NULL) {
			cout << current->data << ", ";
			current = current->next;
		}
		cout << current->data;
	}

	cout << ")" << endl;
}