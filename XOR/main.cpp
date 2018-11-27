#include<iostream>
#include<cmath>
#include<vector>
#include<iterator>
#include<sstream>
#include<string>
//XOR 解码 用于7日之都神密留言


using namespace std;


int Key(int n) {                   //from 7days 

	if (n % 2 == 0)
	{
		return 8 + 7 * n;
	}
	else {
		return  4*((n + 1)/2)*((n + 1) / 2) -1 ;
	}
	
}

int Key_0(int n)
{
	return 8 + 14 * n;
}

int Key_1(int n)
{
	return 4 * (n + 1)*(n + 1) - 1;
}


vector<int>& decode(vector<int> &el)
{
	cout << "================== decode result" << endl;
	for (vector<int>::iterator iter = el.begin(); iter != el.end(); ++iter)
	{
		int index = iter - el.begin();
		el[index] = el[index] ^ Key(index);
		cout << char(el[index]) << endl;
	}

	return el;
}

vector<int>& decode_0(vector<int> &el)
{	
	stringstream ss;
	cout << "================== decode_0 result" << endl;
	for (vector<int>::iterator iter = el.begin(); iter != el.end(); ++iter)
	{
		int index = iter - el.begin();
		el[index] = el[index] ^ Key_0(index);
		cout << char(el[index]);	
	}
	cout<<endl;

	return el;
}

vector<int>& decode_1(vector<int> &el)
{
	cout << "================== decode_1 result" << endl;
	for (vector<int>::iterator iter = el.begin(); iter != el.end(); ++iter)
	{
		int index = iter - el.begin();
		el[index] = el[index] ^ Key_1(index);
		cout << char(el[index]);
	}
	cout << endl;
	return el;
}


vector<int>& decode(vector<int> &el,vector<int> &el2)
{
	cout << "================== decode result" << endl;
	for (vector<int>::iterator iter = el.begin(); iter != el.end(); ++iter)
	{
		int index = iter - el.begin();
		el[index] = el[index] ^ el2[index];
		cout << el[index] << endl;
	}
	return el;
}


int main()
{
	//cout<<(92^8)<<endl;
	//cout <<Key(3)<< endl;

	/*for (int i = 0; i < 10; i++)
	{
		cout << Key(i) << endl;
	}*/

	
	istream_iterator<int>i1(cin), i2;
	vector<int> A(i1,i2);	
	
	/*decode_1(decode_0(A));
	decode_0(decode_1(A));*/
	decode_1(A);
	//decode(A);
	
	

	return 0;
}




