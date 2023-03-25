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
	name = n;
	ID = id;
	age = a;
}
void person::setAge(int a)
{
	age = a;
}
void person::setID(int id)
{
	ID = id;
}
void person::setName(string n)
{
	name = n;
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
