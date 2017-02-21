#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>
#include <sstream>


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

};