#pragma once
#include<iostream>
#include "Node.h"


class Tree {
	TNode<int>* m_root;
public:
	Tree();
	void insertNode(int);
	void printInOrder(TNode<int>*);
	void printPreOrder(TNode<int>*);
	void printPostOrder(TNode<int>*);
	TNode<int>* getRootPtr() {
		return m_root;
	}
};

void Test_Tree();