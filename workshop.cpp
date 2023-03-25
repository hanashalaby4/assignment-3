#include <fstream>
#include <iostream>
using namespace std;
#include "customer.h"
#include "mechanic.h"
#include "queuec.h"

int main()
{

	//reading mechanics details from a file
	int mechAmount, apptAmount; //storing the number of mechanics and the amount of appointments each one has

	ifstream mechanicsInput;
	mechanicsInput.open("mechInfo.txt");

	if (mechanicsInput.fail()) { //checking if file is open
		cout << "failed to open file" << endl;
		exit(1);
	}
	mechanicsInput >> mechAmount;
	mechanic* mechanics = new mechanic[mechAmount];

	/*if (mechanics == nullptr) {
		cout << "failed to allocate memory for mechanics" << endl;
		exit(1);
	}*/

	for (int i = 0; i < mechAmount; i++)
	{
		string name;
		int id, age;
		mechanicsInput >> name >> id >> age >> apptAmount; //storing info in their corresponding variables
		mechanics[i] = mechanic(name, id, age);
		for (int j = 0; j < apptAmount; j++) {
			int h, m;
			mechanicsInput >> h >> m;
			mechanics[i].setApoint(appointment(h, m));  //setting the appointment in the array of appointments for the mechanic
		}
	}
	mechanicsInput.close();

	//reading customers details from a file

	ifstream customersInput;
	customersInput.open("custInfo.txt");

	if (customersInput.fail()) { //checking if file is open
		cout << "failed to open file 2" << endl;
		exit(1);
	}

	int numCustomers;

	customersInput >> numCustomers;
	customer* customers = new customer[numCustomers];

	/*if (customers == nullptr) {
		cout << "Failed to allocate memory for customers" << endl;
		exit(1);*/

		for (int i = 0; i < numCustomers; i++)
		{
			string name;
			int age, id, h, m;
			customersInput >> name >> id >> age >> h >> m;
			customers[i] = customer(name, id, age, appointment(h, m), -1); //declaring an array of customers with unassigned mechanics
		}
		customersInput.close();

		Queue<customer> qCustomers(numCustomers);
		//checking availability
		for (int j = 0; j < numCustomers; j++)
		{
			bool foundMech = false;
			for (int i = 0; i < mechAmount; i++)
			{
				if (mechanics[i].isAvailable(customers[j].getApt())) //if the mechanic is available for the customers appointment time
				{
					customers[j].setmID(i + 1);
					mechanics[i].setApoint(customers[j].getApt()); //sets appointment to the mechanic's array of appointments
					foundMech = true; // mechanic available
					break;
				}
			}
			if (!foundMech) // np mechanics available at the specified time
				cout << "No mechanics" << endl;
		}
		//swap using the overloaded operators to arrange them in order
		for (int i = 0; i <numCustomers;i++)
		{
			for (int j = i; j<numCustomers;j++)
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
		for (int i = 0; i < numCustomers;i++)
		{
			if (customers[i].getmID() != -1)
				qCustomers.push(customers[i]);
		}
		//output to screen
		for (int i = 0; i < numCustomers;i++)
		{
			cout << qCustomers.peek().getName() << " has an appointment at " << qCustomers.peek().getApt().hours << ":" << qCustomers.peek().getApt().mins << " with " << mechanics[i].getName() << "." << endl;
			qCustomers.pop();
		}

		delete[] mechanics;
		delete[] customers; //freeing borrowed space from heap

		return 0;

	}
