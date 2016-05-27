// LinkedListTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "linkedList.h"

using namespace std;

void test_front()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	cout << "front: " << list.front() << endl;
}

void test_back()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	cout << "back: " << list.back() << endl;
}

void test_pos()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	cout << "list[3]: " << list[3] << endl;
}

void test_push_front()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	list.push_front(1);
	cout << "push_front(1): ";
	list.dump();
}

void test_push_back()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	list.push_back(1);
	cout << "push_back(1): ";
	list.dump();
}

void test_insert()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	list.insert(4, 1);
	cout << "insert(4, 1): ";
	list.dump();
}

void test_pop_front()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	list.pop_front();
	cout << "pop_front: ";
	list.dump();
}

void test_pop_back()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	list.pop_back();
	cout << "pop_back: ";
	list.dump();
}

void test_reverse()
{
	LinkedList<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_back(2);
	list.push_back(8);
	list.push_back(3);
	list.push_back(40);

	list.dump();
	list.reverse();
	cout << "reverse: ";
	list.dump();
}

int _tmain(int argc, _TCHAR* argv[])
{
	test_front();
	test_back();
	test_pos();
	test_push_front();
	test_push_back();
	test_insert();
	test_pop_front();
	test_pop_back();
	test_reverse();

	char* str = new char[100];
	cin >> str;

	return 0;
}

