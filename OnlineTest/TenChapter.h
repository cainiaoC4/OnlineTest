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