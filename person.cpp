#include <iostream>
using namespace std;
#include "Person.h"

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
int person::getAge()
{
	return age;
}
int person::getID()
{
	return ID;
}
string person::getName()
{
	return name;
}
void person::printInfo() {}
