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
