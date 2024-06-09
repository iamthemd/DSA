#pragma once
#include <iostream>

using namespace std;

template<typename TYPE>
class DoubleLinkList {
	struct DListStruct {
		DListStruct(TYPE val) {
			_prevPtr = nullptr;
			value = val;
			_nextPtr = nullptr;
		}

		DListStruct* _prevPtr;
		TYPE value;
		DListStruct* _nextPtr;
	};

public:
	
	DoubleLinkList() {
		_headPtr = nullptr;
		_count = 0;
	}

	~DoubleLinkList() {
		if (_headPtr != nullptr) {
			delete _headPtr;
		}
		_headPtr = nullptr;
	}


	void addAtBegin(TYPE val);
	void addAtEnd(TYPE val);
	void addAtMiddle(TYPE val, unsigned int pos);
	void display();

private:
	unsigned int _count;
	DListStruct *_headPtr;
};

template<typename TYPE>
void DoubleLinkList<TYPE>::addAtBegin(TYPE value) {
	DListStruct* temp = new DListStruct(value);
	if (_headPtr == nullptr) {
		_headPtr = temp;
	}
	else {
		_headPtr->_prevPtr = temp;
		temp->_nextPtr = _headPtr;
		_headPtr = temp;
	}
	_count++;
}

template<typename TYPE>
void DoubleLinkList<TYPE>::addAtEnd(TYPE value) {
	DListStruct* temp = new DListStruct(value);
	if (_headPtr == nullptr) {
		_headPtr = temp;
	}
	else {
		DListStruct* itr = _headPtr;
		while (itr->_nextPtr != nullptr) {
			itr = itr->_nextPtr;
		}
		temp->_prevPtr = itr;
		itr->_nextPtr = temp;
	}
	_count++;
}

template<typename TYPE>
void DoubleLinkList<TYPE>::addAtMiddle(TYPE value, unsigned int pos) {
	if (pos < 0) {
		cout << "Please enter valid position greater than 0.";
		return;
	}
	else if (pos == 1) {
		addAtBegin(value);
	}
	else if (pos == _count + 1) {
		addAtEnd(value);
	}
	else{
		DListStruct* temp = new DListStruct(value);
		if (_headPtr == nullptr) {
			_headPtr = temp;
		}
		else {
			DListStruct* itr = _headPtr;
			while (pos > 1) {
				itr = itr->_nextPtr;
				pos--;
			}
			itr->_prevPtr->_nextPtr = temp;
			temp->_nextPtr = itr;
			temp->_prevPtr = itr->_prevPtr;
		}
		_count++;
	}
}

template<typename TYPE>
void DoubleLinkList<TYPE>::display() {
	DListStruct* itr = _headPtr;
	while (itr) {
		cout << itr->value;
		cout << "<-->";
		itr = itr->_nextPtr;
	}
}

void Test_DoubleLinkList() {
	DoubleLinkList<int> d;
	d.addAtMiddle(3, 0);
	d.addAtBegin(2);
	d.addAtEnd(5);
	d.addAtMiddle(4, 3);
	d.display();
}