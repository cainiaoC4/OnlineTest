#pragma once
//线索树,非栈实现深度查询
template<class T>
class ThreadedNode {
public:
	ThreadedNode() {
		left = right = 0;
	}
	ThreadedNode(const T& e,ThreadedNode *l =0,ThreadedNode *r =0) {
		el = e;
		left = l;
		right = r;
		successor = 0;
	}
	T el;
	ThreadedNode *left, *right;
	unsigned int successor : 1;
};

template<class T>
class ThreadedTree {
public:
	ThreadedTree() {
		root = 0;
	}

	void insert(const T&);
	void inorder();

protected:
	ThreadedNode<T>* root;

};

template<class T>
inline void ThreadedTree<T>::insert(const T &el)
{
	ThreadedNode<T>*p, *prev = 0, *newNode;
	NewNode = new ThreadedNode<T>(el);

	if (root == 0)
	{
		root = newNode;
		return;
	}

	p = root;

	while (p != 0) {

		prev = p;
		if(p->el>el)
	}

}

template<class T>
inline void ThreadedTree<T>::inorder()
{
	ThreadedNode<T>*prev, *p = root;

	if (p != 0)
	{
		while (p->left != 0)   // the most left node
		{
			p = p->left;
		}

		while (p != 0) {
			visit(p);
			prev = p;
			p = p->right;
			if (p != 0 && prev->successor == 0)   // successor == 0 means this *r is right child  su==1 mean this *r is father
			{
				while (p->left != 0)              // this right child has left c,go to this c
					p = p->left;
			}
		}
	}
}
