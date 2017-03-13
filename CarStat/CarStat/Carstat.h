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


struct Car
{
	
	int year; //��� �������
	float_t price; //����
	std::string name; //�����

	//destructor
	~Car() {}
	
	//default constructor
	Car();
	//constructor with params
	Car(int inYear, float_t inPrize, string inName);
	
	//overload comaparing operator more than...
	//void operator>(Car rhsCar);

	//implementation of overload comparing operator inside Car struct
	/*void Car::operator>(Car rhsCar)
	{
		if (this.price > rhsCar.price)
			cout << "Price: " << this.price << " more than " << rhsCar.price;
		else
			cout << rhsCar.price << " is more!";
	}
	*/
};

