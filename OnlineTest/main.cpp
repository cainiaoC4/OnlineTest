#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<fstream>
#include<sstream>

#include"EightChapter.h"
#include"NineChapter.h"
#include"TenChapter.h"
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

istream& myStreamLearn(istream& i)
{
	string mm;
	while (i >> mm)
	{
		cout << mm << endl;
	}
	i.clear();
	return i;
}





void multiargv(initializer_list<string> il)
{
	for(auto beg =il.begin();beg!=il.end();++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
}


void PrintArgv(int argc,char* argv[])
{
	string str;
	for (int i = 1; i < argc; ++i)
	{
		str += argv[i];
		str += " ";
	}
	cout << str <<" "<<" function version"<< endl;
}

void OpenFileAndOutPut(char*argv1,char*argv2)
{
	ifstream input(argv1);
	ofstream output(argv2);


}

struct AAA
{
	int a;
	char b;
};

int mystrlen(const char* str)
{
	int count = 0;
	while ((*str) != '\0')
	{
		++count;
		str++;
	}

	return count;
}

int main(int argc,char*argv[])
{
	/*Base1 base1(1);
	Base2 base2(2);
	Base3 base3;

	fun(&base1);
	fun(&base2);
	fun(&base3);*/
	//Derived obj(1, 2, 3, 4);

	///==========================================
	//string fileName ="x.txt";

	////Func_8_10(fileName);
	////Func_8_11();

	//list<int> test = { 1,2,3,4,5,6 };

	//ListInt2VecDouble(test);

	//list<const char*> test2 = { "we","are","right" };
	//ListCharPtr2VecString(test2);

	//Func_10_2();

	//Func_10_X<int>();

	//Func_10_3();
	//Func_10_5();
	//Func_10_6();
	//Func_10_7_2();

	/*char a[10];
	cout << strlen(a) << " " << sizeof(a) << endl;*/
	
	//cout << sizeof(AAA);

	//int a = mystrlen("wat");

	//int a = 0;
	//int b = 1;
	//int c = -2;

	//int n1 = a / b;
	//int n2 = b / c;
	////int n3 = b / a;
	//int n4 = a / c;

	//cout << n1 << n2 << n4;
	
	//Func_10_13();
	std::vector<std::string> myVec;
	//std::vector<int> myVec;
	FillTVector(std::cin,myVec);

	std::string s = "myWords";
	//Func_10_24(myVec, s);
	//Func_10_18(myVec,5);
	//Func_10_22(myVec, 6);
	//Func_10_25(myVec, 6);

	std::list<std::string> mylist;
	Func_10_27(myVec, mylist);

	//ifstream input(fileName);
	//vector<string> vec;
	//if (input)
	//{
	//	string buf;
	//	/*while (getline(input,buf))          //行为单位
	//	{
	//		vec.push_back(buf);
	//	}*/

	//	while (input >> buf)               //空格为间隔
	//	{
	//		vec.push_back(buf);
	//	}
	//}
	//else
	//{
	//	cerr << "can not open this file" << fileName << endl;
	//}
	//
	//cout << vec[1] << endl;

	//PrintArgv(argc,argv);
	
	/*input.open("x.txt");
	if (input)
	{
		input.getline
	}*/

	//if (input)
	//{
	//	myStreamLearn(input);
	//	cout << "success";
	//}
	//else
	//{
	//	cout << "fail";
	//	myStreamLearn(cin);
	//	
	//	//cout << endl;
	//	
	//}

	/*string line, word;
	vector<PersonInfo> people;
	while (getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}

		people.push_back(info);

	}*/

	return 0;
}

//template<typename T>
//void elim(vector<T> &v)
//{
//	sort(v.begin(), v.end());
//
//	auto end_unique = unique(v.begin(), v.end());
//
//	words.erase(end_unique, v.end());
//}


