#include <fstream>
#include <windows.h>
#include <stdexcept>
#include "carstat.h"
using namespace std;

int main() 
{
	
	try
	{
		fstream fileIn; //input file
		//void open(const char *filename, ios::openmode mode);
		fileIn.open("car.txt", ios::in);
		if (!fileIn) {
			//throw invalid_argument("File not found!");
			throw std::runtime_error("File not found!");
		}
		else {
			cout << "car.txt found" << endl;
		}
		
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
		return -1;
	}
	//Ok.
	return 0;
}

