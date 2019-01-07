#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;


template <typename T>
class print {
public:
	void operator() (const T& elem)
	{
		cout << elem << ' ';
	}
};


int main()
{
	int iap[6] = { 0,1,2,3,4,5 };

	vector<int> iv(iap, iap + 6);

	//print<int>()��һ���ݴ���󣬲���һ���������ж���
	for_each(iv.begin(), iv.end(), print<int>());

}