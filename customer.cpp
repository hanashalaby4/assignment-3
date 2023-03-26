
#include <iostream>
using namespace std;
#include "customer.h"


void customer::setApt(const appointment& Apt)
{
	apnt = Apt;
}
void customer::setmID(int mID)
{
	mechanicID = mID;
}
appointment customer::getApt() const
{
	return apnt;
}
int customer::getmID() const
{
	return mechanicID;
}
void customer::printInfo()
{
	cout << getName() << " " << getID() << " " << getAge() << " " << getmID() << " ";
	apnt.printApt();
}
bool customer::operator<(const customer& c2) //overloading < operator
{
	if (apnt.hours < c2.apnt.hours)
		return true;
	else if (apnt.hours == c2.apnt.hours && apnt.mins < c2.apnt.mins)
		return true;
	else
		return false;

	return false;
}
bool customer::operator>(const customer& c2) //overloading > operator
{
	if (apnt.hours>c2.apnt.hours)
		return true;
	else if (apnt.hours == c2.apnt.hours && apnt.mins > c2.apnt.mins)
		return true;
	else
		return false;

	return false;
		
}
bool customer::operator==(const customer& c2) //overloading == operator
{ 
	if (apnt.hours == c2.apnt.hours && apnt.mins == c2.apnt.mins)
		return true;
	else
		return false;
}

