#pragma once
#include"IntSLLNode.h"
#include<iostream>

class IntSLList
{
public:
	IntSLList();
	~IntSLList();

	int isEmpty()
	{
		return head == 0;
	}

	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int) const;

	void showAll();

private:
	IntSLLNode*head, *tail;

	IntSLLNode*prev, *curr;
	int count;
};

