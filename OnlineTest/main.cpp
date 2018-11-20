#include<iostream>
#include<vector>
#include <stdio.h>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

class Base1 {
public:
	Base1() { cout << "默认构造1" << endl; }
	Base1(int i) { cout << "Constructing Base1" << i << endl; }

	void display() const { cout << "Base1::display()" << endl; }
};


class Base2 :public Base1{
public:
	Base2() { cout << "默认构造2" << endl; };
	Base2(int j) { cout << "Constructing Base2" << j << endl; }

	void display() const { cout << "Base2::display()" << endl; }
};

class Base3 :public Base2{
public:
	
	Base3() { cout << "Constructing Base3*" << endl; }

	void display() const { cout << "Base3::display()" << endl; }
};

class Derived :public Base2, public Base1, public Base3 {
public:
	Derived(int a,int b,int c,int d):Base1(a),member2(d),member1(c),Base2(b){}
private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};

void fun(Base1*ptr)
{
	ptr->display();
}


int main()
{
	/*Base1 base1(1);
	Base2 base2(2);
	Base3 base3;

	fun(&base1);
	fun(&base2);
	fun(&base3);*/
	Derived obj(1, 2, 3, 4);


	return 0;
}