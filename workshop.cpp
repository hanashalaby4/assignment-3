#pragma once
#include <iostream>
using namespace std;
#include "customer.h"

int main()
{
	appointment a1, a2;
	a1.hours = 4;
	a1.mins = 20;
	a2.hours = 6;
	a2.mins = 40;
	string n = "hana", n2 = "hala";
	customer c1(n, 123, 18, a1, 4), c2(n2, 12, 21, a2, 5);
	c1.printInfo();
	c2.printInfo();
	if (c1 > c2)
	{
		cout << "customer 1 is served first";
	}
	else cout << " false";
}
