#include <fstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <iostream>
#include <sstream>
#include <stdlib.h> 
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
	
	try
	{
		//void open(const char *filename, ios::openmode mode);
		fileIn.open("car.txt", ios::in);
		if (!fileIn) {
			//throw invalid_argument("File not found!");
			throw std::runtime_error("File not found!");
		}
		else {
			cout << "car.txt found" << endl;
			cout << "Enter year: ";
			cin  >> askYear;
			while (getline(fileIn, aStr))
			{
				aYear = aStr.substr(0, 4); //store year from file line
				if (std::stoi(aYear) >= askYear) //comparing stored year with defined
					{ 	aCars.push_back(aStr);	//store line in vector if it's match
						//cout << aCars[i] << endl; //display which car is added to vector
					}				
				i++;				
			}
		}
		
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}
	
	std::sort(aCars.begin(), aCars.end());
	
	unsigned int k = 0;
	while (k < aCars.size())
	{
		std::string aaYear = aCars[k].substr(0, 4);
		//cout << aCars[k] << endl;
		cout <<  aaYear << endl;
		k++;
	}

	//Ok.
	return 0;
}

