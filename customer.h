#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;
#include "Person.h"

class customer : public person
{
private:
	appointment apnt;
	int mechanicID;
public:
	customer() :person() 
	{
		apnt = { 0,00 };
		mechanicID = 0;
	}
	customer(string n, int id, int a, const appointment& Apt, int mID):
		person(n,id,a), apnt(Apt), mechanicID(mID)
	{}
	void setApt(const appointment& Apt);
	void setmID(int mID);
	appointment getApt() const;
	int getmID() const;
	bool operator<(const customer& c2);
	bool operator>(const customer& c2);
	bool operator==(const customer& c2);
	void printInfo();
	
};


#endif