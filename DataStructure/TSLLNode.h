#pragma once
template<typename T>
class TSLLNode
{
public:
	TSLLNode() {
		next = 0;
	};
	~TSLLNode();

	
	TSLLNode(T i, TSLLNode<T> *in = 0)
	{
		info = i;
		next = in;
	}

	T info;
	TSLLNode *next;
};

template<typename T>
inline TSLLNode<T>::~TSLLNode()
{
}
