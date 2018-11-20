#pragma once
class IntSLLNode
{
public:
	IntSLLNode()
	{
		next = 0;
	};

	IntSLLNode(int i, IntSLLNode *in = 0)
	{
		info = i;
		next = in;
	}
	~IntSLLNode();


	int info;
	IntSLLNode *next;
};

