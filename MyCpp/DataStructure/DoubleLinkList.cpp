#include<iostream>
#include "DoubleLinkList.h"

DoubleLinkList::DoubleLinkList() {
	if (_headPtr != nullptr) {
		delete _headPtr;
		_headPtr = nullptr;
	}
	_headPtr = nullptr;
	_count = 0;
}

void DoubleLinkList::insertAtBegin(int val) {
	DNode *nodeTobeInserted = new DNode();
	nodeTobeInserted->prevPtr = nullptr;
	nodeTobeInserted->nextPtr = nullptr;
	nodeTobeInserted->val = val;
	// If it is first Node.
	if (_headPtr == nullptr) {
		_headPtr = nodeTobeInserted;
	}
	else {

		nodeTobeInserted->nextPtr = _headPtr;
		_headPtr->prevPtr = nodeTobeInserted;
		_headPtr = nodeTobeInserted;
	}
	_count++;
}

void DoubleLinkList::insertAtEnd(int val) {
	DNode* nodeTobeInserted = new DNode();
	nodeTobeInserted->prevPtr = nullptr;
	nodeTobeInserted->nextPtr = nullptr;
	nodeTobeInserted->val = val;
	// If it is first node
	if (_headPtr == nullptr) {
		_headPtr = nodeTobeInserted;
	}
	else {
		DNode* temp = _headPtr;
		while (temp->nextPtr != nullptr) {
			temp = temp->nextPtr;
		}
		nodeTobeInserted->prevPtr = temp;
		temp->nextPtr = nodeTobeInserted;
	}
	_count++;
}

void DoubleLinkList::insertAtMiddle(int pos, int val) {
	if (pos <= 0 || pos > _count + 1) {
		std::cout << "Enter the correct position, currently list contains " << _count << " Entry\n";
		return;
	}

	if (pos == 1) {
		insertAtBegin(val);
		return;
	}
	else if (pos == _count + 1) {
		insertAtEnd(val);
		return;
	}
	DNode* nodeTobeInserted = new DNode();
	nodeTobeInserted->nextPtr = nullptr;
	nodeTobeInserted->prevPtr = nullptr;
	nodeTobeInserted->val = val;
	// If it is the first node or if list is empty.
	if (_headPtr == nullptr) {
		_headPtr = nodeTobeInserted;
	}
	else {
		int i = 1;
		DNode* temp = _headPtr;
		while (i < pos - 1) {
			temp = temp->nextPtr;
			i++;
		}
		nodeTobeInserted->nextPtr= temp->nextPtr;
		nodeTobeInserted->prevPtr = temp;
		temp->nextPtr->prevPtr = nodeTobeInserted;
		temp->nextPtr = nodeTobeInserted;
	}
	_count++;
}

void DoubleLinkList::deleteNodeByPos(int pos) {
	if (pos <= 0 || pos > _count || _count == 0 || _headPtr == nullptr) {
		std::cout << "Failed due to following reason\n";
		std::cout << "incorrect position/List is empty\n";
		return;
	}
	// First node tobe deleted
	if (pos == 1) {
		DNode* nodeTobeDeleted = _headPtr;
		_headPtr = _headPtr->nextPtr;
		_headPtr->prevPtr = nullptr;
		delete nodeTobeDeleted;
	}
	// Last node to be deleted
	else if (pos == _count) {
		DNode* temp = _headPtr;
		while (temp->nextPtr != nullptr) {
			temp = temp->nextPtr;
		}
		temp->prevPtr->nextPtr = nullptr;
		delete temp;
	}
	else {
		DNode* temp = _headPtr;
		DNode* prev = _headPtr;
		int i = 1;
		while (i != pos) {
			prev = temp;
			temp = temp->nextPtr;
			i++;
		}
		DNode* nodeTobeDeleted = temp;
		prev->nextPtr = temp->nextPtr;
		temp->nextPtr->prevPtr = prev;
		delete nodeTobeDeleted;
	}
	_count--;
}

void DoubleLinkList::deleteNodeByVal(int val) {
	if (val < 0 || _count == 0 || _headPtr == 0) {
		std::cout << "Failed due to following reason\n";
		std::cout << "Incorrect value/List iss empty\n";
		return;
	}

	DNode* temp = _headPtr;
	DNode* prev = _headPtr;
	DNode* nodeTobeDeleted = nullptr;
	while (temp != nullptr) {
		if (temp->val == val) {
			nodeTobeDeleted = temp;
			break;
		}
		prev = temp;
		temp = temp->nextPtr;
	}
	if (nodeTobeDeleted == nullptr) {
		std::cout << "Node not found!" << std::endl;
		return;
	}
	// first node to be deleted
	if (prev == temp ) {
		_headPtr = _headPtr->nextPtr;
		delete nodeTobeDeleted;
	}
	else {
		prev->nextPtr = nodeTobeDeleted->nextPtr;
		if(nodeTobeDeleted->nextPtr != nullptr){ // For last not nextPtr will be null
			nodeTobeDeleted->nextPtr->prevPtr = prev;
		}
		delete nodeTobeDeleted;
	}
	_count--;
}

void DoubleLinkList::printList() {
	if (_headPtr != nullptr){
		DNode* ptr = _headPtr;
		while (ptr  != nullptr) {
			std::cout << ptr->val << std::endl;;
			ptr = ptr->nextPtr;
		}
	}
	else {
		std::cout << "List is empty\n";
	}
}

int DoubleLinkList::getSizeOfList() {
	return _count;
}

void Test_DoubleLinkList() {
	DoubleLinkList dLinkList;
	std::cout << "============== Running ===================\n";
	dLinkList.insertAtEnd(4);
	dLinkList.insertAtBegin(3);
	dLinkList.insertAtBegin(2);
	dLinkList.insertAtBegin(1);
	dLinkList.insertAtMiddle(5, 5);
	dLinkList.insertAtEnd(7);
	dLinkList.insertAtMiddle(6, 6);
	dLinkList.insertAtMiddle(1, 0);
	dLinkList.insertAtMiddle(9, 8);
	dLinkList.printList();
	std::cout << "============== Deleting Node by pos ===================\n";
	dLinkList.deleteNodeByPos(1);
	dLinkList.deleteNodeByPos(3);
	dLinkList.deleteNodeByPos(dLinkList.getSizeOfList());
	dLinkList.printList();
	std::cout << "============== Deleting Node by Val ===================\n";
	dLinkList.deleteNodeByVal(1);
	dLinkList.deleteNodeByVal(2);
	dLinkList.deleteNodeByVal(7);
	dLinkList.printList();
}