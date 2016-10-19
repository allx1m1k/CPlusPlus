#pragma once

#include <vector>
#include <string>
#include <initializer_list>

class Child; //forward declaration

class Parent
{ //
public:
	Parent();  //default constructor
	Parent(std::string name, int age);  //constructor with parametr
	~Parent(); //destructor
	void eat();
	void sleep();
	void drink();
	bool hasChildren; //number of Children
	void addChildren(std::vector<std::string> children);
	
	//std::vector<Child> mChildren; //NOK Parent's children, this is vector of refs of Child types
	//void addChildren(Child& children);

protected:
	std::string mParentName; //Parent name
	uint16_t mAge; //Parent age
	std::vector<std::string> mChildren; //Children of Parent

}; //end of Parent

//Parent default constructor
Parent::Parent()
	: hasChildren(false)
	, mParentName("NAN")
	, mAge(0)
	, mChildren(0)
{}

//Parent constructor with formal arument
Parent::Parent(std::string name, int age)
	: hasChildren(0)
	, mParentName(name)
	, mAge(age)
	, mChildren(0)
{}

//Parent instance method
void addChildren(std::vector<std::string> children)
{

}

//Child is ancestor of Parent 
class Child : public Parent
{
public:
	Child();  //default constructor
	~Child(); //destructor

}; //end of Child






