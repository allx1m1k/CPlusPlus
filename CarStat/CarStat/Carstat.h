#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>

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
//. ������� � ����� http://www.programmersforum.ru/showthread.php?t=91445
//������ ��������� ������ � ��������������� ������������ ���������-���������
//��. stl ���������� http://informatics.mccme.ru/mod/book/view.php?id=492&chapterid=200
//. ���������� ������������ ����������� http://www.cplusplus.com/articles/NhA0RXSz/ 


struct Car
{
	std::string brandName; //�����
	float price; //����
	uint16_t year; //��� �������
};