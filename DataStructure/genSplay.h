#pragma once
//C++数据结构与算法分析 6-15


template<class T> class SplayTree;

template<class T>
class SplayingNode {

public:
	SplayingNode() {
		left = right = parent = 0;
	}

	SplayingNode(const T& el, SplayingNode *l = 0, SplayingNode *r = 0, SplayingNode*p = 0) {
		info = el;
		left = l;
		right = r;
		parent = p;
	}
	T info;

	SplayingNode *left, *right, *parent;
		
};


template<class T>

class SplayTree {

public:
	SplayTree() {
		root = 0;
	}

	void inorder() {

		inorder(root);
	}

	T*search(const T&);
	void insert(const T&);


protected:
	SplayingNode<T> *root;
	void rotateR(SplayingNode<T>* p);
	void rotateL(SplayingNode<T>* p);
	void continueRotation(SplayingNode<T>* gr, SplayingNode<T>*par, SplayingNode<T>*ch, SplayingNode<T>*desc);

	void semisplay(SplayingNode<T>* n);
	void inorder(SplayingNode<T>*n);
	void virtual visit(SplayingNode<T>* n) {};

};

template<class T>
void SplayTree<T>::rotateR(SplayingNode<T>* p)
{
	p->parent->left = p->right;
	p->right = p->parent;
	continueRotation(p->parent->parent, p->right, p, p->right->left);
}

template<class T>
 void SplayTree<T>::rotateL(SplayingNode<T>* p)
{
	 p->parent->right = p->left;
	 p->left = p->parent;
	 continueRotation(p->parent->parent, p->right, p, p->left->right);
}

template<class T>
void SplayTree<T>::continueRotation(SplayingNode<T>* gr, SplayingNode<T>* par, SplayingNode<T>* ch, SplayingNode<T>* desc)
{
	if (gr != 0) {
		if (gr->right == ch->parent)
			gr->right = ch;
		else
			gr->left = ch;
	}
	else
		root = ch;
	if (desc != 0)
		desc->parent = par;

	par->parent = ch;
	ch->parent = gr;
}


