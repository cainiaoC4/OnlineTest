#include<iostream>


int main()
{
	const int i = 0;
	//int*j = &i;       ///cannot trans const int* to int*
	int* j = (int*)&i;

	std::cout << *j << std::endl;
	std::cout << j << std::endl;
	std::cout << &i << std::endl;

	*j = 1;
	std::cout << *j << std::endl;
	std::cout << j << std::endl;
	std::cout << &i << std::endl;

	return 0;

}