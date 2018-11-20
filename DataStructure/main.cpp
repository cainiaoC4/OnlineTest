#include"IntSLLNode.h"
#include"IntSLList.h"

#include"TSLLNode.h"
#include <iostream>
using namespace std;

int main()
{
	//IntSLList A;
	//
	//A.addToHead(1);
	//A.addToTail(2);
	//A.addToTail(3);
	//A.addToTail(4);

	////A.deleteFromHead();
	////A.deleteFromTail();
	//A.deleteNode(3);
	////A.deleteNode(1);
	//A.showAll();

	TSLLNode<int>*p =new TSLLNode<int>(1);
	//p->next = new TSLLNode<float>(2.3f);

	cout << p->info << endl;
	return 0;
}