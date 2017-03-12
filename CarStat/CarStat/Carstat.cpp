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
//static virables 

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
	std::vector<Car> *carList = new vector<Car>;
	bool flag = true; //if flag is set then create the Car instance
	int indexYear = 0; //index of year
	int indexPrice = 1; //index of price
	int indexName = 2; //index of name 
	//adding Car instance to the vector
	if (myDelim->size() > 0) {
		for (indexYear; indexYear <= myDelim->size() - 3; indexYear = indexYear + 3) //looping by year 
		{
			flag = true;
			if (flag) {
				for (indexPrice; indexPrice <= myDelim->size() - 2; indexPrice = indexPrice + 3) //looping by price 
				{
					if (flag) {
						for (indexName; indexName <= myDelim->size() - 1; indexName = indexName + 3) //looping by name
						{
							if (flag) {
								int inYear = atoi(myDelim->at(indexYear).c_str()); //populating year
								float_t inPrice = atoi(myDelim->at(indexPrice).c_str()); //populating prise
								std::string inName = myDelim->at(indexName);  //populating brand name					
								carList->push_back(Car(inYear, inPrice, inName)); //passing values to Car constructor	
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
	cout << endl << "carList size is: " << carList->size() << endl;
	//compare two Cars from carList
	//carList->at(0) > carList->at(1);
	
	getCarWithMaxPrice(carList); //call func to evaluate max price
	
	//call the destructor to free memory
	carList->clear();
	//Ok.
	return 0;
}


