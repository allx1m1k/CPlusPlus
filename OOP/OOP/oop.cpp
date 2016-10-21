#include "oop.h"
#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

using namespace std;
const std::string _have = "yes";
const std::string _donthave = "no";

int main()
{
	Parent* bobParent = new Parent("Bob", 40);
	bobParent->eat();
	cout << "Parent " << bobParent->getName() << " has any children? " << (bobParent->hasChildren ? _have : _donthave  ) << endl;
	bobParent->addChildren({"son John"});
	cout << "Parent " << bobParent->getName() << " has any children? " << (bobParent->hasChildren ? _have : _donthave) << endl;
		
}