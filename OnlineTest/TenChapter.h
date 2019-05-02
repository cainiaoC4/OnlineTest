#pragma once
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<numeric>

//std::istream& myStreamLearn(std::istream& i)
//{
//	std::string mm;
//	while (i >> mm)
//	{
//		std::cout << mm << std::endl;
//	}
//	i.clear();
//	return i;
//}


//std::istream& FillintVector(std::istream& i, std::vector<int> &v)
//{
//
//}


template<typename T>
void PrintVectorElem(std::vector<T> &v)
{
	auto index = v.begin();
	std::cout << "Vector Size is " << v.size() << std::endl;

	for (; index < v.end(); ++index)
	{
		std::cout << (*index) << std::endl;
	}

}

template<typename T>
std::istream& FillTVector(std::istream&i, std::vector<T>& v)
{
	T mm;
	while (i >> mm)
	{
		v.push_back(mm);
	}
	i.clear();
	return i;
}



void Func_10_1()
{//��������
	std::cout << "Set Your <int> Vector" << std::endl;
	std::vector<int> myVec;
	FillTVector(std::cin, myVec);

	std::cout << "Search whatever You Like " << std::endl;
	int SearchVal;

	std::cin >> SearchVal;

	int Nums = std::count(myVec.begin(), myVec.end(), SearchVal);

	std::cout<<SearchVal<<" �ĸ���Ϊ " << Nums << std::endl;
}

void Func_10_2()
{//��������
	std::cout << "Set Your <string> Vector" << std::endl;
	std::vector<std::string> myVec;
	FillTVector(std::cin, myVec);

	std::cout << "Search whatever You Like " << std::endl;
	std::string SearchVal;

	std::cin >> SearchVal;

	int Nums = std::count(myVec.begin(), myVec.end(), SearchVal);

	std::cout << SearchVal << " �ĸ���Ϊ " << Nums << std::endl;
}


template<typename T>
void Func_10_X()
{
	std::cout << "Set Your <T> Vector" << std::endl;
	std::vector<T> myVec;
	FillTVector(std::cin, myVec);

	if (std::cin.bad())
	{
		std::cout << " д��Vector�����п�����������" << std::endl;
	}
	else
	{
		std::cout << "Search whatever You Like " << std::endl;
		T SearchVal;

		if (std::cin >> SearchVal)
		{
			int Nums = std::count(myVec.begin(), myVec.end(), SearchVal);

			std::cout << SearchVal << " �ĸ���Ϊ " << Nums << std::endl;
		}
		else
		{
			std::cout << "Wrong input" << std::endl;
		}

	}
	
}


void Func_10_3()
{
	std::cout << "Set Your <int> Vector" << std::endl;
	std::vector<int> myVec;
	FillTVector(std::cin, myVec);

	if (std::cin.bad())
	{
		std::cout << " д��Vector�����п�����������" << std::endl;
	}
	else
	{
		int result = std::accumulate(myVec.begin(), myVec.end(), 0);
		std::cout << "Vector<int> �ܺ�Ϊ " << result << std::endl;
	}
}


void Func_10_5()
{
	/*const char*a = "Watme";
	const char*b = "hellU";
	const char* c = "Watme";*/
	std::vector<const char*> a = {"Watme","HellU","Byeme","Tok"};
	std::vector<const char*> b = { "Watme","HellU","Byeme","Tok" };
	std::vector<const char*> c = { "Watme","HellxU","Byemex","Toxk" };
	//std::cout << a[0] << std::endl;

	bool result =std::equal(a.begin(), a.end(), c.begin());

	std::cout << result << std::endl;
}


void Func_10_6() {

	std::cout << "Set Your <int> Vector" << std::endl;
	std::vector<int> myVec;
	FillTVector(std::cin, myVec);

	if (std::cin.bad())
	{
		std::cout << " д��Vector�����п�����������" << std::endl;
	}
	else
	{
		std::cout << "print the vector" << std::endl;

		PrintVectorElem(myVec);

		std::cout << "Now try fill_n to set elem in 0" << std::endl;
		std::fill_n(myVec.begin(),myVec.size(),0);

		PrintVectorElem(myVec);
		//myVec.reserve()
	}

}


void Func_10_7_1()
{
	std::vector<int> vec; std::list<int> lst; int  i;

	while (std::cin >> i)
	{
		lst.push_back(i);
	}

	vec.reserve(lst.size());
	copy(lst.cbegin(), lst.cend(), vec.begin());
}


void Func_10_7_2()
{
	std::vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
}

void elimDups(std::vector<std::string> &words)
{

	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

bool isShorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}


void Func_10_11()
{
	//��д����ʹ��stable_sort��isShorter��vector������֤���
	std::vector<std::string> mywords;

	FillTVector(std::cin, mywords);
	stable_sort(mywords.begin(), mywords.end(), isShorter);

	PrintVectorElem(mywords);
}



bool myPredicate(const std::string &s1)
{
	return s1.size() > 5;
}
void Func_10_13()
{
	std::vector<std::string> mywords;
	FillTVector(std::cin, mywords);

	//partition ʹν��Ϊtrue��ֵ������������ǰ�벿�֡�
	partition(mywords.begin(), mywords.end(), myPredicate);

	PrintVectorElem(mywords);
}

//lambda����
//������һ���㷨�����κ�����callable object�������e��һ���ɵ��õı��ʽ�������ǿ��Ա�д����e(args).
//lambda���ʽ��ʾһ���ɵ��õĴ��뵥Ԫ��һ��lambda����һ���������͡�һ�������б�һ�������壬���뺯����ͬ�������Զ����ں����ڲ���
//[capture list](parameter list)->return type{function body}
//capture list��һ��lambda���ں����ж���ľֲ��������б�
// auto f =[]{return 42;}
//cout << f() << endl;
//��capture list ����lambda��ʹ�������ں����е��κξֲ�����
//stable_sort(word.begin(),words.end(),[](const string &a,const string &b){return a.size()<b.size();})


void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), isShorter);

	auto l = find_if(words.begin(), words.end(), [sz](const std::string &a) {return a.size() >= sz; });
	auto count = words.end() - l;
	std::cout << count << std::endl;

	for_each(l, words.end(), [](const std::string &s) {std::cout << s << " "; });//����ֱ�Ӷ�����iostream�ļ��ڵı���
}

void Func_10_14(int m,int n)
{
	auto f = [](int a, int b) {return a + b; };
	std::cout << f(m,n) << std::endl;
}

void Func_10_15(int m)
{
	auto f = [m](int a) {return m + a; };
	std::cout << f(5) << std::endl;
}

void Func_10_18(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), isShorter);

	//auto l = find_if(words.begin(), words.end(), [sz](const std::string &a) {return a.size() >= sz; });
	auto l = partition(words.begin(), words.end(), [sz](const std::string &a) {return a.size() <= sz; });
	auto count = words.end() - l;
	std::cout << count << std::endl;

	for_each(l, words.end(), [](const std::string &s) {std::cout << s << " "; });//����ֱ�Ӷ�����iostream�ļ��ڵı���

}