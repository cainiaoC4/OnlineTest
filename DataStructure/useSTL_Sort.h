#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>


class Person {
public:
	Person(char*n , int a = 0) {
		name = strdup(n);
		age = a;
	}

	bool operator ==(const Person& p)const {
		return strcmp(name, p.name) == 0;
	}

	bool operator<(const Person& p)const {
		return strcmp(name, p.name)<0;
	}

private:
	char*name;
	int age;
	friend std::ostream& operator<<(std::ostream& out, const Person& p) {
		std::cout << "(" << p.name << "," << p.age << ")";
		return out;
	}
};


bool f1(int n)
{
	return n < 5;
}


template<class T>
void printVector(char*s, const std::vector<T>& v) {
	std::cout << s << "=(";

	if (v.size() == 0)
	{
		std::cout << ")\n"; 
		return;
	}

	for (std::vector<T>::const_iterator i = v.begin(); i != v.end() - 1; i++)
		std::cout << *i << ',';

	std::cout << *i << ")\n";
}
