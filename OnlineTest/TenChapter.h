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


std::istream& FillintVector(std::istream& i, std::vector<int> &v)
{

}


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
{//存在问题
	std::cout << "Set Your <int> Vector" << std::endl;
	std::vector<int> myVec;
	FillTVector(std::cin, myVec);

	std::cout << "Search whatever You Like " << std::endl;
	int SearchVal;

	std::cin >> SearchVal;

	int Nums = std::count(myVec.begin(), myVec.end(), SearchVal);

	std::cout<<SearchVal<<" 的个数为 " << Nums << std::endl;
}

void Func_10_2()
{//存在问题
	std::cout << "Set Your <string> Vector" << std::endl;
	std::vector<std::string> myVec;
	FillTVector(std::cin, myVec);

	std::cout << "Search whatever You Like " << std::endl;
	std::string SearchVal;

	std::cin >> SearchVal;

	int Nums = std::count(myVec.begin(), myVec.end(), SearchVal);

	std::cout << SearchVal << " 的个数为 " << Nums << std::endl;
}


template<typename T>
void Func_10_X()
{
	std::cout << "Set Your <T> Vector" << std::endl;
	std::vector<T> myVec;
	FillTVector(std::cin, myVec);

	if (std::cin.bad())
	{
		std::cout << " 写入Vector错误，有可能类型问题" << std::endl;
	}
	else
	{
		std::cout << "Search whatever You Like " << std::endl;
		T SearchVal;

		if (std::cin >> SearchVal)
		{
			int Nums = std::count(myVec.begin(), myVec.end(), SearchVal);

			std::cout << SearchVal << " 的个数为 " << Nums << std::endl;
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
		std::cout << " 写入Vector错误，有可能类型问题" << std::endl;
	}
	else
	{
		int result = std::accumulate(myVec.begin(), myVec.end(), 0);
		std::cout << "Vector<int> 总和为 " << result << std::endl;
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
		std::cout << " 写入Vector错误，有可能类型问题" << std::endl;
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

	partition(mywords.begin(), mywords.end(), myPredicate);

	PrintVectorElem(mywords);
}