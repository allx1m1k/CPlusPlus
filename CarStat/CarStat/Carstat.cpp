#include <fstream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <stdexcept>
#include "carstat.h"
using namespace std;
//
fstream fileIn; //input file
Car aCar;
std::string aStr; //a file line which has car data
std::vector<std::string> aCars; //a array of car data
std::vector<Car> aStructCars; //a array of car data via Car struct
//std::vector<string> aCars;
int i = 0;

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
			while (getline(fileIn, aStr))
			{
				aCars.push_back(aStr); //store a data in vector of strings
				//aStructCars.push_back(aStr);
				string &ref = aStr;
				aStructCars[i] = Car(ref);
				//cout << aStr << endl;
				cout << aCars[i] << endl;
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

	int k = 0;
	while (k < aCars.size())
	{
		std::string aYear = aCars[k].substr(0, 4);
		//cout << aCars[k] << endl;
		cout <<  aYear << endl;
		k++;
	}

	//Ok.
	return 0;
}

