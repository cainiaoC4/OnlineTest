#pragma once
// generic binary search tree

#include<queue>
#include<stack>

using namespace std;


template<class T>
class Stack:public stack<T>{};

template<class T>
class Queue :public queue<T> {
public:
	T dequeue() {
		T tmp = front();
		queue<T>::pop();
		return tmp;
	}

	void enqueue(const T& el)
	{
		push(el);
	}


};


template<class T>
class BSTNode {
public :
	BSTNode() {
		left = right = 0;
	}
	BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
		el = e;
		left = l;
		right = r;
	}
	T el;
	BSTNode<T>*left, *right;
};


template<class T>
class BST {
public:
	BST() { root = 0; }
	~BST() { clear(); }

	void clear() {
		clear(root); root = 0;
	}

	bool isEmpty()const {
		return root == 0;
	}

	void preorder() {
		preorder(root);
	}

	void inorder() {
		inorder(root);
	}

	void postorder() {
		postorder(root);
	}

	T* search(const T&el) const {
		return search(root, el);
	}

	void breadthFirst();
	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();
	void MorrisInorder();
	void MorrusPreorder();

	void reverse(BSTNode<T>*from, BSTNode<T>*to);
	void printReverse(BSTNode<T>*from, BSTNode<T>*to);

	void MorrisPostorder();


	void insert(const T&);
	void deleteByMerging(BSTNode<T>*&);
	void findAndDeleteByMerging(const T&);
	void deleteByCopying(BSTNode<T>*&);
	void balance(T*, int, int);

protected:

	BSTNode<T>*root;
	void clear(BSTNode<T>*);
	T* search(BSTNode<T>*, const T&)const;
	void preorder(BSTNode<T>*);
	void inorder(BSTNode<T>*);
	void postorder(BSTNode<T>*);
	virtual void visit(BSTNode<T>* p) {
		cout << p->el << ' ';
	}
};

template<class T>
inline T * BST<T>::search(BSTNode<T>*p, const T &el) const
{   //二叉树查找

	while (p != 0)
	{
		if (el == p->el) {
			return &p->el;
		}
		else if(el<p->el){
			p = p->left;
		}
		else
			p = p->right;
	}

	return NULL;
}

template<class T>
inline void BST<T>::preorder(BSTNode<T>*p)
{
	if (p != 0)
	{
		visit(p);
		preorder(p->left);
		preorder(p->right);
	}
}

template<class T>
inline void BST<T>::inorder(BSTNode<T>*p)
{   //中序遍历
	if (p != 0)
	{
		inorder(p->left);
		visit(p);
		inorder(p->right);
	}
}

template<class T>
inline void BST<T>::postorder(BSTNode<T>*p)
{//后序遍历
	if (p != 0)
	{
		postorder(p->left);
		postorder(p->right);
		visit(p);
	}
}

template<class T>
inline void BST<T>::breadthFirst()
{//广度优先遍历
	Queue<BSTNode<T>*>queue;
	BSTNode<T>*p = root;
	if (p != 0)
	{
		queue.enqueue(p);

		while (!queue.empty())
		{
			p = queue.dequeue();
			visit(p);
			if (p->left != 0)
			{
				queue.enqueue(p->left);
			}

			if (p->right != 0)
			{
				queue.enqueue(p->right);
			}
		}
	}
}

template<class T>
inline void BST<T>::iterativePreorder()
{//前序遍历非递归实现
	Stack<BSTNode<T>*> travStack;
	BSTNode<T>*p = root;

	if (p != 0)
	{
		travStack.push(p);
		while (!travStack.empty())
		{
			p = travStack.pop();
			visit(p);
			if (p->right != 0)
			{
				travStack.push(p->right);
			}
			if (p->left != 0)
			{
				travStack.push(p->left);
			}
		}
	}
}

template<class T>
inline void BST<T>::iterativeInorder()
{ //中序遍历的非递归实现
	Stack<BSTNode<T>*> travStack;
	BSTNode<T>*p = root;
	while (p != 0) {
		while (p != 0)
		{
			if (p->right)
				travStack.push(p->right);
			travStack.push(p);
			p = p->left;
		}
		p = travStack.pop();
		while (!travStack.empty() && p->right == 0)
		{
			visit(p);
			p = travStack.pop();
		}
		visit(p);
		if (!travStack.empty())
			p = travStack.pop();
		else p = 0;

	}
}

template<class T>
inline void BST<T>::iterativePostorder()
{   //后序遍历非递归实现
	Stack<BSTNode<T>*>travStack;
	BSTNode<T>*p = root, *q = root;

	while (p != 0)
	{
		for (; p->left != 0; p = p->left)
		{
			travStack.push(p);
		}
		while (p->right == 0 || p->right == q)
		{
			visit(p);
			q = p;
			if (travStack.empty())
				return;

			p = travStack.pop();
		}
		travStack.push(p);
		p = p->right;
	}
}



//Morris Inorder   Break the structure
//While 
//  if this node has no left child
//     visit this node
//     turn to right child
//  else let this node become left child tree's most right node's right child
//       turn to this left child tree
template<class T>
inline void BST<T>::MorrisInorder()
{  //Morris  中序遍历
   // see: http://note.youdao.com/noteshare?id=72fb0dc580f38af8367ebfa155e45187&sub=6AF1326CF6454A4C81171D9B66F64113

	BSTNode<T> *p = root, *tmp;
	while (p != 0)
	{
		if (p->left == 0)  //no left tree ? turn to right tree
		{
			visit(p);
			p = p->right;           //back to father
		}
		else {
			tmp = p->left;
			while (tmp->right != 0 && tmp->right != p)
				tmp = tmp->right;

			if (tmp->right == 0)
			{
				tmp->right = p;               //let father be right
				p = p->left;
			}
			else {
				visit(p);
				tmp->right = 0;
				p = p->right;
			}
		}
	}
}

template<class T>
inline void BST<T>::MorrusPreorder()
{
	BSTNode<T> *p = root, *tmp;
	while (p != 0)
	{
		if (p->left == 0)  //no left tree ? turn to right tree
		{
			visit(p);
			p = p->right;           //back to father
		}
		else {
			tmp = p->left;
			while (tmp->right != 0 && tmp->right != p)
				tmp = tmp->right;

			if (tmp->right == 0)
			{
				visit(p);
				tmp->right = p;               //let father be right
				p = p->left;
				
			}
			else {
				tmp->right = 0;
				p = p->right;
			}
		}
	}
}

template<class T>
inline void BST<T>::reverse(BSTNode<T>* from, BSTNode<T>* to)
{  //将  t->right 链倒序
	if (from == to)         //only one node
		return;
	BSTNode<T> *x = from, *y = from->right, *z;

	while (true)
	{
		z = y->right;
		y->right = x;
		x = y;
		y = z;
		if (x == to)
		{
			break;
		}
	}
}

template<class T>
void BST<T>::printReverse(BSTNode<T>* from, BSTNode<T>* to)
{
	reverse(from, to);

	BSTNode<T>*p = to;

	while (true)
	{
		visit(p);
		if (p == from) {               //only one node
			break;
		}
		p = p->right;
	}

	reverse(to, from);
}

template<class T>
void BST<T>::MorrisPostorder()
{
	BSTNode<T> dump(0);

	dump.left = root;

	BSTNode<T> *curr = &dump, *prev = 0;

	while (cur)
	{
		if (curr->left == 0)                        //到达最左节点
		{
			curr = curr->right;
		}
		else {
			prev = curr->left;

			while (prev->right != 0 && prev->right != curr)                //寻找右子树的最右节点
				prev = prev->right;


			if (prev->right == 0)
			{
				prev->right = curr;
				curr = curr->left;
			}
			else {

				printReverse(curr->left, prev);
				prev->right = 0;
				curr = curr->right;
			}

		}

	}

}

template<class T>
void BST<T>::insert(const T &)
{
	BSTNode<T>*p = root, *prev = 0;
	while (p != 0) {
		prev = p;
		if (el < p->el)
		{
			p=p->left;
		}
		else {
			p = p->right;
		}
	}
	if (root == 0) {
		root = new BSTNode<T>(el);
	}
	else if (el < prev->el) {
		prev->left = new BSTNode<T>(el);
	}
	else {
		prev->right = new BSTNode<T>(el);
	}
}

template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*&node)
{//合并删除

	BSTNode<T>*tmp = node;

	if (node != 0)
	{
		if (!node->right)                   //没有右孩子，左子树将被贴到其父节点上
		{
			node = node->left;
		} 
		else if(node->left==0)               //没有左孩子，右子树将被贴到其父节点上
		{
			node = node->right;
		}
		else {
			tmp = node->left;

			while (tmp->right != 0)     //查询node左子树的最右节点
			{
				tmp = tmp->right;
			}

			tmp->right = node->right;   //节点右子树被贴到左子树的最右节点的右孩子处。

			tmp = node;

			node = node->left;       //node左子树贴到父节点处
			
		}

		delete tmp;

	}

}

template<class T>
void BST<T>::findAndDeleteByMerging(const T &el)
{//

	BSTNode<T> *node = root, *prev = 0;

	while (node != 0)
	{
		if (node->el == el)
			break;

		prev = node;
		if (node->el < el)
		{
			node=node->right
		}
		else
		{
			node = node->left;
		}
	}

	if (node != 0 && node->el == el)
	{
		if(node==root)
		{
			deleteByMerging(root);
		}
		else if (prev->left == node)
		{
			deleteByMerging(prev->left);
		}
		else {
			deleteByMerging(prev->right);
		}
	}
	else if(root!=0) {
		cout << "Key" << el << "is not in the tree\n";
	}
	else {
		cout << "the tree is empty\n";
	}
}


