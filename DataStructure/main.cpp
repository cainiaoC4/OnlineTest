#include"IntSLLNode.h"
#include"IntSLList.h"

#include"TSLLNode.h"
#include"TSLList.h"
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


	TSLList<float> A;


	A.addToHead(1.2f);
	A.addToTail(2.3f);
	A.addToTail(4.7f);
	A.addToTail(5.5f);
	A.showAll();
	//cout << p->info << endl;
	return 0;
}