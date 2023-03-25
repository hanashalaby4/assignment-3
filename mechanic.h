#pragma once
#include <iostream>
using namespace std;
#include "person.h"
#include "customer.h"


class mechanic : public person {
private:
	appointment* apnts = new appointment[count];//array of booked timings for the mechanic
	int count;
public:
	mechanic() :person() { count = 0; apnts = NULL; }
	mechanic(string n, int id, int a) :person(n, id, a) {
		count = 0; //initializing counter to 0
		apnts = NULL; //pointer to null because no appointments yet
	}
	void printInfo(); //prints the mechanic's details and appointments for the day
	bool isAvailable(const appointment& apt); //checks if the mechanic is available at a given time
	void setApoint(const appointment& a); //adds an appointment to the mechanic's schedule
	
	int getCount() const;
};
