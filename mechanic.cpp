#include <iostream>
using namespace std;

#include "mechanic.h"
void mechanic::setCount(int cnt)
{
	count = cnt;
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
