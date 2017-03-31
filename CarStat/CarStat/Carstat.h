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
Имеется файл, в каждой строке которого хранится запись о проданном авто.
Необходимо вывести на экран информацию о самом дорогом проданном авто,
год выпуска которого не старше заданного.
*/


struct Car
{
	
	int year; //год выпуска
	float_t price; //цена
	std::string name; //бренд

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

