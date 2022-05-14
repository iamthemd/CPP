#pragma once
#include<iostream>
#include "Node.h"


class Tree {
	TNode* m_root;
public:
	Tree();
	void insertNode(int);
	void printInOrder(TNode*);
	void printPreOrder(TNode*);
	void printPostOrder(TNode*);
	TNode* getRootPtr() {
		return m_root;
	}
};

void Test_Tree();