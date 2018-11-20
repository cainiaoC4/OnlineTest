#include "IntSLList.h"



IntSLList::IntSLList()
{
	head = tail = 0;
	prev = curr = 0;
	count = 0;
}


IntSLList::~IntSLList()
{
	for (IntSLLNode*p; !isEmpty();)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

void IntSLList::addToHead(int el)
{
	head = new IntSLLNode(el, head);
	if (tail == 0)
	{
		tail = head;
	}
}

void IntSLList::addToTail(int el)
{
	if (tail != 0)
	{
		tail->next= new IntSLLNode(el, 0);
		tail = tail->next;
	}
	else {
		head = tail = new IntSLLNode(el, 0);
	}
	
}

int IntSLList::deleteFromHead()
{
	if(isEmpty())
	{
		std::cout << "can not delete List is empty" << std::endl;
		return 0;
	}
	else
	{
		int el = head->info;
		IntSLLNode*tmp = head;
		if (head == tail)
		{
			head = tail = 0;
		}
		else
		{
			head = head->next;
		}
		delete tmp;
		return el;
	}


}

int IntSLList::deleteFromTail()
{
	if (isEmpty())
	{
		std::cout << "can not delete List is empty" << std::endl;
		return 0;
	}

	int el = tail->info;
	if (head == tail)
	{
		delete tail;
		head = tail = 0;
	}
	else {
		IntSLLNode*tmp = head;
		for (; tmp->next != tail; tmp = tmp->next)
		{}
			delete tail;
			tail = tmp;
			tail->next = 0;
		
	}
	return el;
	
}

void IntSLList::deleteNode(int el)
{
	if (isEmpty())
	{
		std::cout << "can not delete List is empty" << std::endl;
	}
	else {
		if (head == tail && el == head->info)
		{
			delete head;
			head = tail = 0;
		}
		else {
			IntSLLNode*pred, *tmp;
			for (pred = head, tmp = head;
				tmp != 0 && !(tmp->info == el);
				pred = tmp, tmp = tmp->next
				)
			{}
			if (tmp != 0)              //tmp=tmp->next   防止tmp指针指向尾节点的下一个空节点
			{
				pred->next = tmp->next;
				if (tmp == tail)
				{
					tail = pred;     //查询节点在末尾
				}
				delete tmp;
			}
			
		}



	}


}

bool IntSLList::isInList(int el) const
{
	IntSLLNode*tmp;
	for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp!=0;
}

void IntSLList::showAll()
{
	prev = head;
	curr = head;

	for (; curr != 0; prev = curr, curr = curr->next)
	{
		std::cout << curr->info << std::endl;
	}
}
