#include <iostream>
using namespace std;
#include "Person.h"

person::person()
{
	name = " ";
	ID = 0;
	age = 0;
}
person::person(string n, int id, int a)
{
	this->name = n;
	this->ID = id;
	this->age = a;
}
void person::setAge(int a)
{
	this->age = a;
}
void person::setID(int id)
{
	this->ID = id;
}
void person::setName(string n)
{
	this->name = n;
}
int person::getAge() const
{
	return age;
}
int person::getID() const
{
	return ID;
}
string person::getName() const
{
	return name;
}
void person::printInfo() {}
