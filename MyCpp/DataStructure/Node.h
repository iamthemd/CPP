#pragma once

typedef struct Node {
	unsigned int val;
	Node() {
		nextPtr = nullptr;
	}
	Node(int i):val(i){
		nextPtr = nullptr;
	}
	Node* nextPtr;
}Node;

; typedef struct DNode {
	unsigned int val;
	DNode* nextPtr;
	DNode* prevPtr;
}DNode;

template<typename Type>
struct TNode {
	Type val;
	TNode* left;
	TNode* right;
};
