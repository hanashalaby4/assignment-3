#pragma once
#include <iostream>
using namespace std;
#include "Person.h"

class customer : public person
{
private:
	appointment apnt;
	int mechanicID;
public:
	customer(string n, int id, int a, const appointment& Apt, int mID):
		person(n,id,a), apnt(Apt), mechanicID(mID)
	{}
	void setApt(const appointment& Apt);
	void setmID(int mID);
	appointment getApt();
	int getmID();
	bool operator<(const customer& c2);
	bool operator>(const customer& c2);
	bool operator=(const customer& c2);
	void printInfo();
	
};


