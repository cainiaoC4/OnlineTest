#pragma once
#include"TSLLNode.h"
#include<assert.h>

template<typename T >
class TSLList
{
public:
	TSLList();

	~TSLList();

	int isEmpty() {
		return head == 0;
	}

	void addToTail(T el);
	void addToHead(T el);
	void deleteFromHead();
	void deleteFromTail();
	void deleteNode(T el);
	bool isInList(T el) const;

	void showAll();


private:
	TSLLNode<T>*head, *tail;
	TSLLNode<T>*prev, *curr;     //сн╠Й

	int count;

};


template<typename T>
TSLList<T>::TSLList()
{
	head = tail = 0;
	prev = curr = 0;
	count = 0;
}





template<typename T>
TSLList<T>::~TSLList()
{
	for (TSLLNode<T>*p; !isEmpty();)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

template<typename T>
void TSLList<T>::addToTail(T el)
{
	if (tail != 0) {
		tail->next = new TSLLNode<T>(el);
		tail = tail->next;


		count++;
	}
	else    //empty list 
	{
		head = tail = new TSLLNode<T>(el);

		count++;
	}
}

template<typename T>
void TSLList<T>::addToHead(T el)
{
	head = new TSLLNode<T>(el, head);
	if (tail == 0)             //empty list
	{
		tail = head;

		/*prev = head;
		curr = head;*/
	}
	count++;

	/*prev = curr;
	curr = tail;*/
}

template<typename T>
void TSLList<T>::deleteFromHead()
{
	if (isEmpty())      // is head == 0?
	{
		std::cout << "can not delete List is empty" << std::endl;
		assert(0);
	}
	else
	{
		T el = head->info;
		TSLLNode<T>*tmp = head;
		if (head == tail)           //list has only one element
		{
			head = tail = 0;
		}
		else
		{
			head = head->next;
		}

		delete tmp;                //release the head 

		count--;
		return el;
	}
}

template<typename T>
void TSLList<T>::deleteFromTail()
{
	if (isEmpty())
	{
		std::cout << "can not delete list is empty" << std::endl;
		assert(0);
	}

	int el = tail->info;
	if (head = tail)   //only one element
	{
		delete tail;
		head = tail = 0;
	}
	else
	{
		TSLLNode<T>*tmp = head;
		for (; tmp->next != tail; tmp = tmp->next) {}   //find the element before the tail  ,can not use *prev and *curr to store the tail and that elem because of addToHead()

		//now tmp is that elem
		delete tail;
		tail = tmp;
		tail->next = 0;

	}

	count--;
	return el;

}

template<typename T>
void TSLList<T>::deleteNode(T el)
{
	if (isEmpty())
	{
		std::cout << "can not delete List is empty" << std::endl;
	}
	else {
		if (head == tail && el == head->info)           //only one elem and  el is head.info
		{
			delete head;
			head = tail = 0;
		}
		else
		{
			TSLLNode<T>*pred, *tmp;
			for (pred = head, tmp = head;
				tmp != 0 && !(tmp->info == el);
				pred = tmp, tmp = tmp->next
				) {
			}                               //to find the first elem whos info is el

	  //now tmp is that elem or tmp is tail->next (0)

			if (tmp != 0)
			{
				pred->next = tmp->next;        //link prev elem to curr->next elem 
				if (tmp = tail)               // that elem is tail
				{
					tail = pred;
				}

				delete tmp;


			}

		}
		count--;
	}

}

template<typename T>
bool TSLList<T>::isInList(T el) const
{
	TSLLNode<T>*tmp;
	for (tmp = head; tmp != 0 && tmp->info != el; tmp = tmp->next);       //find the first elem whos info is el

	//now tmp is that elem or tmp to the tail->next
	return tmp != 0;
}

template<typename T>
void TSLList<T>::showAll()
{
	prev = curr = head;

	for (; curr != 0; prev = curr, curr = curr->next)
	{
		std::cout << curr->info << std::endl;
	}
}

