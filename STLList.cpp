// STLList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

template <typename T> class myList; 
template <typename T> class mylist_iterator;

template <typename T>
class mylist_node
{
private:
	T elem;
	mylist_node<T> *next;
	mylist_node(const T& val)
	{
		elem = val;
		next = nullptr;
	}
	~mylist_node()
	{
			delete next;
	}
public:

	friend class myList<T>;
	friend class mylist_iterator<T>;
};


template <typename T>
class mylist_iterator
{
	friend class myList<T>;

public:
	T& operator*();
	const mylist_iterator<T>& operator++();
	bool operator!=(const mylist_iterator<T>& other) const;
private:
	mylist_node<T> *pointee;
	mylist_iterator(mylist_node<T> *pointee) : pointee(pointee) {}

};
template <typename T>
T& mylist_iterator<T>::operator*()
{
	return pointee->elem;
}
template <typename T>
const mylist_iterator<T>& mylist_iterator<T>::operator++()
{
	pointee = pointee->next;
	return *this;
}
template <typename T>
bool mylist_iterator<T>:: operator!=(const mylist_iterator<T>& other) const
{
	return this->pointee != other.pointee;
}




template <typename T>
class myList
{	

public:
	typedef mylist_iterator<T> iterator;
public:
	myList() : head(nullptr), tail(nullptr) {}
	~myList() { delete head; }
	bool empty() const 
	{
		return head == nullptr; 
	}
	void push_back(const T& elem);
	iterator begin() { return mylist_iterator<T>(head); }
	iterator end() { return mylist_iterator<T>(nullptr); }
private:
	mylist_node<T> *head, *tail;
};

template <typename T>
void myList<T>::push_back(const T& elem)
{
	mylist_node<T> *newNode = new mylist_node<T>(elem);
	if (head == nullptr) {
		head = newNode;
	}
	else {
		tail->next = newNode;
	}
	tail = newNode;
}

int main()
{
	myList<string> ivies;
	ivies.push_back("Harvard");
	ivies.push_back("Yale");
	ivies.push_back("Princeton");
	ivies.push_back("Penn");
	myList<string>::iterator begin = ivies.begin();
	myList<string>::iterator end = ivies.end();
	while (begin.operator!=(end)) {
		if (begin.operator*() == "Princeton") {
			cout << "Princeton’s an Ivy."<< endl;
			return 0;
		}
		begin.operator++();
	}
	cout << "They’re all snobs anyway."<< endl;
    cout << "Hello World!\n"; 
	return 0;
}
