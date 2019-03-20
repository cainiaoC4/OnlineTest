#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};

void Func_8_10(std::string fileName)
{
	std::ifstream input(fileName);
	
	std::vector<std::string> vec;

	if(input){
		std::string buf;

		while (std::getline(input, buf))
		{
			vec.push_back(buf);
		}
	}
	
	for (int i = 0; i < vec.size(); ++i)
	{
		std::istringstream sin(vec[i]);

		std::string word;
		while (sin >> word)
		{
			std::cout << word << std::endl;
		}
	}
	
}


void Func_8_11()
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record;
	while (std::getline(std::cin, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
}


void Func_8_13(std::string fileName)
{

	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record;

	std::ifstream fStream(fileName);
	while (std::getline(fStream, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
}


