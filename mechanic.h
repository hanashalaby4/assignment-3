#pragma once
#include <iostream>
using namespace std;
#include "person.h"
#include "customer.h"


class mechanic : public person {
private:
	appointment apnts[10];//asumed max size is 10, this the array of appointments a mechanic has per day
	int count;
public:
	mechanic();
	mechanic(string n, int id, int a); 
	void printInfo(); //prints the mechanic's details and appointments for the day
	bool isAvailable(const appointment& apt) const; //checks if the mechanic is available at a given time
	void setApoint(const appointment& a); //adds an appointment to the mechanic's schedule
	void setCount(int cnt);
	int getCount() const;
};
