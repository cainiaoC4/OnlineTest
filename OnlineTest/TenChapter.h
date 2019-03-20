#pragma once
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

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
{
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
{
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

	if (std::cin.failbit)
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
