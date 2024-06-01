#pragma once
#include<iostream>
using namespace std;

template<typename TYPE>
class SingleLinkList {
	struct ListStruct {
		ListStruct(TYPE val) :value(val){
			nextPtr = nullptr;
		}
		TYPE value;
		ListStruct* nextPtr;
	};

public:

	// Constructor
	SingleLinkList() {
		_headPtr = nullptr;
		_count = 0;
	}

	// Destructor
	~SingleLinkList() {
		if (_headPtr != nullptr) {
			delete _headPtr;
		}
		_headPtr = nullptr;
	}

	void addAtBegin(const TYPE value);
	void addAtEnd(const TYPE value);
	void addAtMiddle(const TYPE value, unsigned int pos);
	void Display();

private:
	ListStruct* _headPtr;
	unsigned int _count;
};

template<typename TYPE>
void SingleLinkList<TYPE>::addAtBegin(const TYPE value) {
	ListStruct* temp = new ListStruct(value);
	// _headPtr contins no node.
	if (_headPtr == nullptr) {
		_headPtr = temp;
	}
	else { // _headPtr contains list of node.
		temp->nextPtr = _headPtr;
		_headPtr = temp;
	}
	_count++;
}

template<typename TYPE>
void SingleLinkList<TYPE>::addAtEnd(const TYPE value) {
	ListStruct* temp = new ListStruct(value);
	// _headPtr contins no node.
	if (_headPtr == nullptr) {
		_headPtr = temp;
	}
	else { // _headPtr contains list of node.
		ListStruct* itr = _headPtr;
		while (itr->nextPtr != nullptr) {
			itr = itr->nextPtr;
		}
		itr->nextPtr = temp;
	}
	_count++;
}

template<typename TYPE>
void SingleLinkList<TYPE>::addAtMiddle(const TYPE value, unsigned int pos) {
	if (pos > _count + 1) {
		cout << "Enter correct position, List of nodes count is " << _count << "\n";
		cout << "You can Enter position between 1 - " << _count + 1 << "\n Thank you!";
	}
	ListStruct* temp = new ListStruct(value);
	// _headPtr contins no node.
	if (_headPtr == nullptr) {
		_headPtr = temp;
	}
	else if (pos == 1) {
		addAtBegin(value);
	}
	else if (pos == _count + 1) {
		addAtEnd(value);
	}
	else { // _headPtr contains list of node.
		ListStruct* itr = _headPtr;
		while (pos-2 > 0) {
			itr = itr->nextPtr;
			pos--;
		}
		// first -> next | second ->next | third -> next | fourth->next
		temp->nextPtr = itr->nextPtr;
		itr->nextPtr = temp;
	}
	_count++;
}

template<typename TYPE>
void SingleLinkList<TYPE>::Display() {
	cout << "============= Single Link List ===================\n";
	if (_count == 0) {
		cout << "List contains no node!, please add atleast one node to display!\n";
		return;
	}
	ListStruct* temp = _headPtr;
	while (temp != nullptr) {
		cout << "|" << temp->value << "|";
		temp = temp->nextPtr;
		if (temp != nullptr)
			cout << " --> ";
	}
}

void Test_SingleLinkList() {
	SingleLinkList<int> sll;
	sll.addAtBegin(5);
	sll.addAtBegin(4);
	sll.addAtBegin(3);
	sll.addAtEnd(6);
	sll.addAtEnd(7);
	sll.addAtBegin(1);
	sll.addAtMiddle(2, 2);
	sll.addAtMiddle(8, 8);
	sll.Display();
}