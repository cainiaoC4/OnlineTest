#include <iostream>  
#include<cstring>


std::string(&funcs(int i))[10];



int main(int argc, char *argv[])

{

//	stlport::crope myrope("Hello world!");
//
//	/*std::cout << myrope << std::endl;
//	stlport::printf(myrope);
//*/
//	system("pause");

	using F = int(*)(int*, int);

	int odd[] = { 1,3,5,7,9 };
	decltype(odd) *arrPtr(int i);

	std::string tenS[] = { "1" ,"2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" ,"10" };

	auto func(int i)->std::string(&)[10];

	decltype(tenS) &arrPref(int i);           //只是声明，若使用，链接器报错




	//std::cout<<arrPref(1);

	return 0;

}

