#include <fstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include "Carstat.h"
using namespace std;

//Car constructor be default
Car::Car() 
:year(0)
,price(0.00)
,name("")
{}

//Car constructor from passed values
Car::Car(int inYear, float_t inPrize, string inName) 
:year(inYear)
,price(inPrize)
,name(inName)
{
	cout << "creating a new Car: " << year << " " << price << " " << name << endl;
}

//implementation of overloaded comparing operator with two formal arguments outside the Car structure
bool operator>(Car carOne, Car carTwo)
{
	if (carOne.price > carTwo.price)
	{
		return true;
	}
	else
	{
		return false;
	}
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

/*
Create vector of filtered by year Cars
*/
std::vector<Car>* createCarList(vector<string>* v)
{
	//TODO: add second argument to this method in order to avoid creating vector in method
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
Displaying tokens from vector of strings
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

int main() 
{
	//local virables
	fstream fileIn; //input file
	std::string aStr; //a file line which has car data
	std::string aYear = "";  //input from file
	int askYear = 0; //user input will be compared with input from file
	std::vector<string> *myDelim = new std::vector<string>; //alocate mem in heap
	try
	{
		//void open(const char *filename, ios::openmode mode);
		fileIn.open("car.txt", ios::in);
		if (!fileIn) {
			//throw invalid_argument("File not found!");
			throw std::runtime_error("File not found!");
		}
		else 
		{
			cout << "car.txt found" << endl;
			cout << "Enter year: ";
			cin  >> askYear;
			while (getline(fileIn, aStr)) //read a line from file
			{
				aYear = aStr.substr(0, 4); //extract year from file line
				if (std::stoi(aYear) >= askYear) //add only line which is matches the criteria	
					mySplitToStrVector(aStr, ';', myDelim); //parse a line to vector
			}
		}
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}

	printTokens(myDelim); //displaying the token elements from vector
	cout << endl << myDelim->size() << " tokens found" << endl;

	//populating the vector of Cars 
	std::vector<Car> *carListFunc =  createCarList(myDelim);
	//std::vector<Car> *carList = new vector<Car>;

	cout << endl << "carListFunc size is: " << carListFunc->size() << endl;
	//TODO: compare two Cars from carList without not suitable method getCarWithMaxPrice
	//carList->at(0) > carList->at(1);
	
	getCarWithMaxPrice(carListFunc); //call func to evaluate max price, unfortunately Car struct doesn't utilized
	
	//call the destructor to free memory
	carListFunc->clear();
	
	//Ok.
	return 0;
}


