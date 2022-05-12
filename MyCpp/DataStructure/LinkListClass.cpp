#include "LinkListClass.h"

LinkListClass::LinkListClass() {
	cout << "In LinkListClass\n";
	if (headPtr != nullptr) {
		delete headPtr;
	}
	headPtr = nullptr;
	_count = 0;
}

int LinkListClass::getSizeofLinkList() {
	return _count;
}

void LinkListClass::insertAtBegin(int val) {
	Node* temp = new Node();
	temp->val = val;
	temp->nextPtr = nullptr;

	Node* itr = headPtr;
	if (itr != nullptr) {
		// Add the node at the beginng of List.
		temp->nextPtr = headPtr;
	}
	// If there is no node entry in List or we could say it is the first entry in List.	
	headPtr = temp;
	_count++;	
}

void LinkListClass::insertAtMiddle(int pos, int val) {
	// If requested for first position.
	if (pos == 1) {
		insertAtBegin(val);
		return;
	}
	else if (pos == _count+1) {
		insertAtEnd(val);
		return;
	}

	Node* temp = new Node();
	temp->val = val;
	temp->nextPtr = nullptr;

	if (headPtr != nullptr && pos <= _count) {
		Node* ptr = headPtr;
		int i = 1;
		while (i < pos-1) {
			ptr = ptr->nextPtr;
			i++;
		}
		temp->nextPtr = ptr->nextPtr;
		ptr->nextPtr = temp;
	}
	else { // There is no entry in List. List is empty.
		headPtr = temp;
	}
	_count++;
}

void LinkListClass::insertAtEnd(int val) {
	Node* temp = new Node();
	temp->val = val;
	temp->nextPtr = nullptr;

	Node* itr = headPtr;
	if (itr != nullptr) {
		// Iterate the list untill get nullptr or last node.
		while (itr->nextPtr != nullptr)
		{
			itr = itr->nextPtr;
		}
		itr->nextPtr = temp;
	}
	else { // If there is no node entry in List or we could say it is the first entry in List.	
		headPtr = temp;
	}
	_count++;
}

void LinkListClass::deleteNodeByVal(int val) {
	if (val < 0 || _count == 0 || headPtr == nullptr) {
		std::cout << "Failed due to following reason\n";
		std::cout << "Incorrect value/Linklist is empty\n";
		return;
	}

	Node* temp = headPtr;
	Node* prev = headPtr;
	Node* deleteNode = nullptr;
	while (temp != nullptr) {
		if (temp->val == val)
			deleteNode = temp;
			break;
		prev = temp;
		temp = temp->nextPtr;
	}
	if (deleteNode == nullptr) {
		std::cout << "Node not found!" << std::endl;
		return;
	}
	// first node to be delete
	if (prev == temp) {
		headPtr = headPtr->nextPtr;
		delete deleteNode;
		_count--;
	}
	else {
		prev->nextPtr = temp->nextPtr;
		delete deleteNode;
		_count--;
	}
}

void LinkListClass::deleteNodeByNo(int Num) {
	if (Num <= 0 || Num > _count || _count == 0 || headPtr == nullptr) {
		std::cout << "Failed due to following reason\n";
		std::cout << "Incorrect Num/Linklist is empty\n";
		return;
	}
	Node* temp = headPtr;
	Node* prev = headPtr;
	Node* deleteNode = nullptr;
	
	for (int i = 1; i <= Num; i++) {
		if (i == Num) {
			deleteNode = temp;
			break;
		}
		prev = temp;
		temp = temp->nextPtr;
	}
	// First node to be deleted
	if (Num == 1) {
		headPtr = headPtr->nextPtr;
		delete deleteNode;
		_count--;
	}
	else {
		prev->nextPtr = temp->nextPtr;
		delete deleteNode;
		_count--;
	}
}

void LinkListClass::printList() {
	if (headPtr != nullptr) {
		Node* ptr = headPtr;
		while (ptr != nullptr) {
			cout << ptr->val << "\n";
			ptr = ptr->nextPtr;
		}
	}
	else { // There is no entry in List. List is empty.
		cout << "There is no entry in LinkList\n";
	}
}

void LinkListClass::printList(Node* ptr) {
	if (ptr) {
		std::cout << ptr->val << " ";
		printList(ptr->nextPtr);
	}
}

void LinkListClass::printListReverse(Node* ptr) {
	if (ptr) {
		printListReverse(ptr->nextPtr);
		std::cout << ptr->val << " ";
	}
}

void Test_SingleLinkList() {
	cout << "============== Running ===================\n";
	LinkListClass obj;
	obj.insertAtEnd(4);
	obj.insertAtBegin(3);
	obj.insertAtBegin(2);
	obj.insertAtBegin(1);
	obj.insertAtMiddle(5, 5);
	obj.insertAtEnd(7);
	obj.insertAtMiddle(6,6);
	obj.insertAtMiddle(1, 0);
	obj.insertAtMiddle(9, 8);
	obj.printList();
	cout << "------------ Delting Node by value -------------------\n";
	obj.deleteNodeByVal(0);
	obj.deleteNodeByVal(2);
	obj.deleteNodeByVal(9);
	obj.printList();
	cout << "------------ Deleting Node By Number -------------------\n";
	obj.deleteNodeByNo(1);
	obj.deleteNodeByNo(3);
	obj.deleteNodeByNo(7);
	obj.printList(obj.getHeadPtr());
	cout << "------------ Print List in reverse order -------------------\n";
	obj.printListReverse(obj.getHeadPtr());
}
