#include <iostream>
using namespace std;

#include "mechanic.h"
mechanic::mechanic() :person(), count(0) {
	
	for (int i = 0; i < 10; i++)
	{
		apnts[i].hours = 0;
		apnts[i].mins = 0;

	}
}
mechanic::mechanic(string n, int id, int a) :person(n, id, a) {
	this->count = 0;//initializing counter to 0
	for (int i = 0; i < 10; i++)
	{
		apnts[i].hours = 0;
		apnts[i].mins = 0;

	}
}
void mechanic::setCount(int cnt)
{
	this->count = cnt;
}
void mechanic::printInfo()
{
	cout << getName() << " " << getID() << " " << getAge() << " " << getCount() << endl;
	for (int i = 0; i < getCount(); i++)
	{
		apnts[i].printApt();
	}
	
}

void mechanic::setApoint(const appointment& a)
{
	apnts[++count] = a;
}
bool mechanic::isAvailable(const appointment& apt) const
{
	for (int i = 0; i < count; i++)
	{
		if (apnts[i].hours == apt.hours && apnts[i].mins == apt.mins)
			return false;
	}	
			return true;
}

int mechanic::getCount() const
{
	return count;
}
