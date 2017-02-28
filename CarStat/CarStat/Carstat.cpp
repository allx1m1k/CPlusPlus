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
//
fstream fileIn; //input file
std::string aStr; //a file line which has car data
std::vector<std::string> aCars = {""}; //a array of car data
std::string aYear = "";
//std::vector<Car> aStructCars; //a array of car data via Car struct
//std::vector<string> aCars;
int i = 0;
int askYear = 0;

int main() 
{
	
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
			//std::vector<string> myDelim = {};		
			while (getline(fileIn, aStr)) //read a line from file
			{
				 //mySplitToCharToken(aStr, ';');
				aYear = aStr.substr(0, 4); //extract year from file line
				if (std::stoi(aYear) >= askYear) //add only line which is fulfill	
					mySplitToStrVector(aStr, ';', myDelim); //parse a line to vector
			}
		}
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}
	/*
	Displaying tokens
	*/
	int k = 0;
	cout << endl << "Displaying tokens from myDelim vector" << endl;
	while (k < myDelim->size())
	{
		//std::string aaYear = aCars[k].substr(0, 4);
		cout << myDelim->at(k);
		//cout <<  aaYear << endl;
		k++;
		cout << endl;
	}
	//populating the vector of Cars structure
	std::vector<Car> *carList = new vector<Car>;
	int j = 0;
	while (j < myDelim->size())
	{
		//carList->at(j) = Car(myDelim);
		carList->push_back(Car(myDelim));
		j++;
	}

	cout << carList->size();
	
	//printCarList(carList);

	//single car works Ok
	//Car *singleCar = new Car(myDelim);
	
	//Ok.
	return 0;
}

