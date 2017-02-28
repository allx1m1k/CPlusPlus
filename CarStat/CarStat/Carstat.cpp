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
	cout << endl << myDelim->size() << " tokens found" << endl;
	bool flag = true; //if flag is set then create the Car instance
	int i = 0; //index of year
	int kk = 1; //index of price
	int j = 2; //index of name 
	//adding Car to the vector
	if (myDelim->size() > 0) {
		for (i; i <= myDelim->size() - 3; i = i + 3) //looping by year 
		{
			flag = true;
			if (flag) {
				for (kk; kk <= myDelim->size() - 2; kk = kk + 3) //looping by price 
				{
					if (flag) {
						for (j; j <= myDelim->size() - 1; j = j + 3) //looping by name
						{
							if (flag) {
								int inYear = atoi(myDelim->at(i).c_str()); //populating year
								float_t inPrice = atoi(myDelim->at(kk).c_str()); //populating prise
								std::string inName = myDelim->at(j);  //populating brand name					
								carList->push_back(Car(inYear, inPrice, inName)); //passing values to constructor	
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
			//flag = true;
		}
	}
	cout << endl << "carList size is: " << carList->size() << endl;
	//call the destructor to free memory
	carList->clear();
	//Ok.
	return 0;
}

