#pragma once
#include<vector>
#include<deque>
#include<list>

void Func_9_2()
{
	std::list<std::deque<int>> mylist;
}


bool Func_9_4(std::vector<int>::iterator l,std::vector<int>::iterator r,int val)
{
	std::vector<int>::iterator min = l < r ? l : r;
	std::vector<int>::iterator max = l < r ? r : l;

	for (std::vector<int>::iterator beg = min; beg != max; ++beg)
	{
		if (*beg == val)
		{
			return true;
		}
	}

	
	return false;
}


std::vector<int>::iterator Func_9_5(std::vector<int>::iterator l, std::vector<int>::iterator r, int val)
{
	std::vector<int>::iterator min = l < r ? l : r;
	std::vector<int>::iterator max = l < r ? r : l;

	for (std::vector<int>::iterator beg = min; beg != max; ++beg)
	{
		if (*beg == val)
		{
			return beg;
		}
	}


	return max;
}


void InitVector()
{
	std::vector<int> myVec = { 1,2,3,4,5,6,7 };
	std::vector<float> myVec2(10, 1.23f);
	std::vector<int> myVec6(10);
	std::vector<int> myVec3(myVec);
	std::vector<int> myVec4;
	std::vector<int> myVec5(myVec.begin(), myVec.end());
}




void ListInt2VecDouble(std::list<int> &l)
{
	std::vector<double> test1(l.begin(), l.end());

	std::cout << test1[0] << std::endl;
}


void VecInt2VecDouble(std::vector<int> &v)
{
	std::vector<double> test(v.begin(), v.end());

	std::cout << test[0] << std::endl;
}


void ListCharPtr2VecString(std::list<const char*> &l)
{
	std::vector<std::string> myVec;
	myVec.assign(l.begin(), l.end());

	std::cout << myVec[1] << std::endl;
}


bool Func_9_15(std::vector<int> &v1,std::vector<int> &v2)
{
	if (v1 == v2)
	{
		return true;
	}

	return false;

}


bool Func_9_16(){}
