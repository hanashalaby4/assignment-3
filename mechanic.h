#pragma once
#include <iostream>
using namespace std;
#include "person.h"
#include "customer.h"


class mechanic : public person {
private:
	appointment* apnts; //array of booked timings for the mechanic
	int count;
public:
	mechanic(string n, int id, int a) :person(n, id, a) {
		count = 0; //initializing counter to 0
		apnts = NULL; //pointer to null because no appointments yet
	}
	void printInfo();
	bool isAvailable(const appointment& apt);
	void setApoint(const appointment& a);
	appointment* getApoints();
	int getCount();
};
