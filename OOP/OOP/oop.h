#pragma once

#include <vector>
#include <string>
#include <initializer_list>
#include <iostream>

class Parent
{ //
public:
	Parent();  //default constructor
	Parent(std::string name, int age);  //constructor with parametr
	~Parent(); //destructor
	void eat();
	void sleep();
	void drink();
	std::string getName();
	bool hasChildren; //flag
	void addChildren(std::vector<std::string> children);
	//const std::vector<Child> mChildren; //NOK Parent's children, this is vector of refs of Child types
	//void addChildren(Child& children);

private: //always incapsulate the internal data
	std::string mParentName; //Parent name
	std::uint16_t mAge; //Parent age
	std::vector<std::string> mChildren; //Parent childrens

}; //end of Parent

//Parent default constructor
Parent::Parent()
	: hasChildren(false)
	, mParentName("NAN")
	, mAge(0)
	, mChildren()
{}

//Parent constructor with formal arument
Parent::Parent(std::string name, int age)
	: hasChildren(0)
	, mParentName(name)
	, mAge(age)
	, mChildren()
{}

//Parent instance method eat
void Parent::eat()
{
	

}

//get Parent name
std::string Parent::getName()
{
	return mParentName;
}

//Parent instance method addChildren
void Parent::addChildren(std::vector<std::string> children)
{
	std::cout << "adding children... " << std::endl;
	mChildren = { children }; //add childrens to internal data element - vector
	hasChildren = true;
	
}

//Child is ancestor of Parent 
class Child : public Parent
{
public:
	Child();  //default constructor
	~Child(); //destructor

}; //end of Child






