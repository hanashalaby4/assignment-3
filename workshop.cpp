
#include <iostream>
using namespace std;
#include "customer.h"
#include "mechanic.h"
#include "queuec.h"

const int MAX_MECHANICS = 3;
const int MAX_CUSTOMERS = 4;

int main()
{
	// Read mechanics' data from the user or initialize them within the main function
	mechanic mechanics[MAX_MECHANICS];
	mechanics[0].setName("Ayman");
	mechanics[1].setName("Khaled");
	mechanics[2].setName("Jana");

	// Read customers' data from the user
	customer customers[MAX_CUSTOMERS];
	customers[0].setName("Ahmed");
	customers[0].setApt({ 1, 0 });
	customers[0].setID(1);
	customers[1].setName("Sara");
	customers[1].setApt({ 4, 0 });
	customers[1].setID(2);
	customers[2].setName("Kareem");
	customers[2].setApt({ 3, 0 });
	customers[2].setID(3);
	customers[3].setName("Mohammed");
	customers[3].setApt({ 1, 0 });
	customers[3].setID(4);


	Queue<customer> qCustomers(MAX_CUSTOMERS);
	//checking availability
	for (int j = 0; j < MAX_CUSTOMERS; j++)
	{
		bool foundMech = false;
		for (int i = 0; i < MAX_MECHANICS; i++)
		{
			if (mechanics[i].isAvailable(customers[j].getApt()))
			{
				customers[j].setmID(i + 1);
				mechanics[i].setApoint(customers[j].getApt());
				foundMech = true;
				break;
			}
		}
		if (!foundMech)
			cout << "No mechanics" << endl;
	}
	//swap
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		for (int j = i; j < MAX_MECHANICS; j++)
		{
			if (customers[i] > customers[j])
			{
				customer temp = customers[i];
				customers[i] = customers[j];
				customers[j] = temp;
			}
		}
	}
	//pushing into queue
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		qCustomers.push(customers[i]);
	}

	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		cout << qCustomers.peek().getName() << " has an appointment at " << qCustomers.peek().getApt().hours << ":" << qCustomers.peek().getApt().mins << " with " << mechanics[i].getName() << "." << endl;
		qCustomers.pop();
	}

}