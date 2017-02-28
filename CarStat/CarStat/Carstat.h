#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <iostream>
#include <stdlib.h> 
using namespace std;

/*
������� ����, � ������ ������ �������� �������� ������ � ��������� ����.
���������� ������� �� ����� ���������� � ����� ������� ��������� ����,
��� ������� �������� �� ������ ���������.
*/


//.� �++11 ������� ������� api ��� ������ � ������� - ��������� ���
//https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm
//fstream https://msdn.microsoft.com/en-us/library/k8w40w6t.aspx
//. ������� ��������� �� ����� http://ci-plus-plus-snachala.ru/?p=2177
//.��-������� ������� �� ����� �� ������� (��� ������� <= �������� ���)
//��. ��� http://www.cplusplus.com/forum/beginner/208388/#msg982326
//.msdn ��-�������� ������� �����
//https://msdn.microsoft.com/uk-ua/library/94223t4d.aspx
//.string substr
//http://www.cplusplus.com/reference/string/string/substr/
//.sort
//http://www.cplusplus.com/reference/algorithm/sort/
//. ������� � ����� http://www.programmersforum.ru/showthread.php?t=91445
//������ ��������� ������ � ��������������� ������������ ���������-���������
//��. stl ���������� http://informatics.mccme.ru/mod/book/view.php?id=492&chapterid=200
//. ���������� ������������ ����������� http://www.cplusplus.com/articles/NhA0RXSz/ 


struct Car
{
	int year; //��� �������
	float_t price; //����
	std::string name; //�����

	//destructor
	~Car() {}
	
	//����������� ��� ����������
	Car(): 
		year(0),
		price(0.00),
		name("")
	{}
	
	//����������� �� ������, ��������� �� �����
	//http://stackoverflow.com/questions/27098305/parsing-string-into-struct-variables
	//http://www.cplusplus.com/reference/sstream/istringstream/
	Car(std::string &str)
	{
		//parse year
		std::string *strYear = new std::string; //allocate mem for year in str
		std::size_t loc = str.find(';'); //delimiter
		*strYear = str.substr(0, loc);  //assign new value of year
		year = atoi(strYear->c_str()); //from str to int year
		//parse price and name
		std::istringstream iss(str.substr(loc));
		//iss >> price >> name;
	}

	//constructor from vektor
	Car(vector<string> *v)
	{
		for (int k = 0; k < (v->size() - 2); k++)
		{
			year = atoi(v->at(k).c_str()); //populating year
			price = atoi(v->at(k + 1).c_str()); //populating prise
			name = v->at(k + 2);  //populating brand name
		}
	}

	//constructor from passed values
	Car(int inYear, float_t inPrize, string inName):
		year(inYear), price(inPrize), name(inName)
	{	
		cout << "creating a new Car: " << year << " " << price << " " << name << endl;
	}

};

/* 
Split a string by a delim, and return a vector of strings 
containing no delim
*/
std::vector<string> mySplitToCharToken(const string &s, char delim) 
	{
		stringstream ss(s);
		string item;
		vector<string> tokens;
		while (getline(ss, item, delim)) 
		{
			tokens.push_back(item);
		}
		return tokens;
	}
/*
string& s - input 
delim - delimeter
vector<string>* v - output
http://ysonggit.github.io/coding/2014/12/16/split-a-string-using-c.html
*/
void mySplitToStrVector(const string s, char delim, vector<string>* v) {
	auto i = 0;
	auto pos = s.find(delim);
	while (pos != string::npos) {
		v->push_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);

		if (pos == string::npos)
			v->push_back(s.substr(i, s.length()));
	}
}

void printCarList(vector<Car>* s) {
	cout << endl << "Displaying Cars from car list" << endl;
	for (int k = 0; k < s->size(); k++)
	{
		//cout << s->at(k) << endl;
		//price = atoi(s->at(k + 1).c_str()); //populating prise
		//name = v->at(s + 2);  //populating brand name
	}

}
