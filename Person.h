#pragma once
#include <iostream>
using namespace std;


class person {
private:
	string name;
	int ID, age;
public:

	person(string n, int id, int a);
	void setName(string n);
	void setID(int id);
	void setAge(int a);
	string getName();
	int getID();
	int getAge();
	virtual void printInfo() = 0;
};
struct appointment
{
	int hours;
	int mins;
	appointment();
	appointment(int h, int m)
	{
		if (h < 0 || h>23)//validation for time
			hours = -1;   //24 hour format
		else
			hours = h;

		if (m < 0 || m>59)
			mins = -1;
		else
			mins = m;

	}
	void printApt() 
	{
		cout << hours << ":" << mins << endl;
	}
};
