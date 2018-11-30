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
void BST<T>::insert(const T &el)
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
{//合并删除  ,可能导致树的高度升高或降低

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

	////find that node 
	while (node != 0)                           //试图于从被删除节点的父节点的左或者右指针数据成员中访问节点。
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


	//

	if (node != 0 && node->el == el)     
	{
		if(node==root)                      
		{
			deleteByMerging(root);
		}
		else if (prev->left == node)                // that node is prev's left child ,
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

template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node)
{  
	//复制删除。         //不对称，因为总是删除node中键值的直接前驱节点，降低了左子树高度，在执行插入操作后，右子树高度增加
	BSTNode<T> *previous, *tmp = node;

	if (node->right == 0) {                //右子树为空，则将左孩子覆盖到node
 		node = node->left;
	}
	else if(node->left ==0)               //左子树为空，将右孩子覆盖到node
	{
		node = node->right;
	}
	else {                                //
		tmp = node->left;
		previous = node;

		while (tmp->right != 0)         //查询node左子树的最右节点及其父节点previous
		{
			previous = tmp;
			tmp = tmp->right;
		}

		node->el = tmp->el;             //左子树最右节点的键值赋值给被删除节点。

		if (previous == node)           //node->left 没有右子树
		{
			previous->left = tmp->left;             //将node左子树的最右节点的左子树 接到node左指针处。
		}
		else {
			previous->right = tmp->left;            //node左子树的最右节点的左子树接到最右节点的右指针处。
		}
	}
	delete tmp;


}



template<class T>
void BST<T>::balance(T data[], int first, int last)
{
	//树中任一节点的两个子树的高度差为0或者1，该二叉树就是高度平衡的。
	//10000个元素存储在完全平衡树中，树的高度就是lg(10001) =13.289 =14

	//当数据到达时，将其全部存储在一个数组中，用某种高效算法对数组进行排序！

	//将数组中间的元素指定为根，产生两个子数组，分别balance迭代

	//缺陷是在创建树之前，所有数据必须放在数组中，这些数据可以直接输入到数组中，当必须使用树，但是准备保存到树中的数据仍然在输入的时候就不合适了。
	//可以通过中序遍历将不平衡树的数据传送到数组中，删除原树，使用balance重新创建树就OK了。
	if (first <= last)
	{
		int middle = (first + last) / 2;

		insert(data[middle]);
		balance(data, first, middle - 1);
		balance(data, middle + 1, last);
	}
}


