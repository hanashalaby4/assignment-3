#include <iostream>
using namespace std;

#include "mechanic.h"

void mechanic::printInfo()
{
	cout << getName() << " " << getID() << " " << getAge() << " " << getCount() << endl;
	for (int i = 0; i < getCount(); i++)
	{
		apnts->printApt();
		apnts++;
	}
	apnts = apnts - getCount();
}

void mechanic::setApoint(const appointment& a)
{
	apnts = new appointment[++count];
}
bool mechanic::isAvailable(const appointment& apt)
{
	for (int i = 0; i < count; i++)
	{
		if (apnts->hours == apt.hours && apnts->mins == apt.mins)
			return false;
		else if (apnts->hours == apt.hours && apnts->mins != apt.mins)
			return true;
		else
			return true;
			
		apnts++;
	}
	apnts = apnts - (count);
	return false;

}

int mechanic::getCount() const
{
	return count;
}
