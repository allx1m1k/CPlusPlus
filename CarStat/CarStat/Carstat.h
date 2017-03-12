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
»меетс€ файл, в каждой строке которого хранитс€ запись о проданном авто.
Ќеобходимо вывести на экран информацию о самом дорогом проданном авто,
год выпуска которого не старше заданного.
*/



struct Car
{

	int year; //год выпуска
	float_t price; //цена
	std::string name; //бренд


	//destructor
	~Car() {}
	
	//конструктор без параметров
	Car(): 
		year(0),
		price(0.00),
		name("")
	{}
	
	//конструктор из строки, считанной из файла
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

	//overload comaparing operator more than...
	void operator>(Car rhsCar);

};
//implementation of overload operator 
void Car::operator>(Car rhsCar)
{
	if (price > rhsCar.price)
		cout << "Price: " << price << " more than " << rhsCar.price;
	else
		cout << rhsCar.price << " is more!";
}


/*
Split a line by a delim, and return a vector of tokens containing no delim
string& s - input 
delim - delimeter
vector<string>* v - output
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

/*
Displaying tokens
*/
void printTokens(vector<string>* v)
{
	int k = 0;
	cout << endl << "Displaying tokens from myDelim vector" << endl;
	while (k < v->size())
	{
		cout << v->at(k);
		//cout <<  aaYear << endl;
		k++;
		cout << endl;
	}
}

std::vector<Car>* createCarList(vector<string>* v)
{
	std::vector<Car> *aList = new vector<Car>; //allocate memory

	bool flag = true; //if flag is set then create the Car instance
	int indexYear = 0; //index of year
	int indexPrice = 1; //index of price
	int indexName = 2; //index of name 
					   //adding Car instance to the vector
	if (v->size() > 0) {
		for (indexYear; indexYear <= v->size() - 3; indexYear = indexYear + 3) //looping by year 
		{
			flag = true;
			if (flag) {
				for (indexPrice; indexPrice <= v->size() - 2; indexPrice = indexPrice + 3) //looping by price 
				{
					if (flag) {
						for (indexName; indexName <= v->size() - 1; indexName = indexName + 3) //looping by name
						{
							if (flag) {
								int inYear = atoi(v->at(indexYear).c_str()); //populating year
								float_t inPrice = atoi(v->at(indexPrice).c_str()); //populating prise
								std::string inName = v->at(indexName);  //populating brand name					
								aList->push_back(Car(inYear, inPrice, inName)); //passing values to Car constructor	
							}
							else break;
							flag = false;
						}
					}
					else break;
					flag = false;
				}
			}
			else break;
		}
	}
	return aList;
}


/* 
Evaluating max price in carList
*/
void getCarWithMaxPrice(vector<Car> *carList)
{
	//local varibles
	float_t maxPrice = 0;
	float_t temp = 0;
	int carIndex = 0;
	int maxIndex = 0;
	while (carIndex < carList->size())
	{
		temp = carList->at(carIndex).price;
		if (temp > maxPrice)
		{
			maxPrice = temp;
			maxIndex = carIndex;
		} 
		carIndex = carIndex + 1;
	}
	cout << "Max price in CarList is: " << maxPrice << " at index " << maxIndex << endl;
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
