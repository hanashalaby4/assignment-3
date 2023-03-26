#include <iostream>
#include <fstream>
#include "customer.h"
#include "mechanic.h"
#include "queuec.h"
using namespace std;


int main()
{

	//reading mechanics details from a file
	int mechAmount, apptAmount; //storing the number of mechanics and the amount of appointments each one has

	ifstream mechanicsInput("mechInfo.txt");

	mechanicsInput >> mechAmount;
	mechanic* mechanics = new mechanic[mechAmount];

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

	ifstream customersInput("custInfo.txt");

	int numCustomers;

	customersInput >> numCustomers;
	customer* customers = new customer[numCustomers];



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
		int Index;
		for (int i = 0; i < mechAmount && !foundMech && customers[i].getmID() == -1; i++)
		{
			if (mechanics[i].isAvailable(customers[j].getApt())) //if the mechanic is available for the customers appointment time
			{
				int Index = j % mechAmount;
				mechanics[Index].setApoint(customers[j].getApt()); //sets appointment to the mechanic's array of appointments
				customers[j].setmID(Index);
				foundMech = true; // mechanic available
			}
		}
	}

	

	//swap using the overloaded operators to arrange them in order
	for (int i = 0; i < numCustomers; i++)
	{
		for (int j = i; j < numCustomers; j++)
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
	for (int n = 0; n < numCustomers; n++)
	{
			qCustomers.push(customers[n]);
	}
	//output to screen
	for (int i = 0; i < mechAmount+1; i++)
	{
		int Index = i % mechAmount;
		cout << qCustomers.peek().getName() << " has an appointment at " << qCustomers.peek().getApt().hours << ":" << qCustomers.peek().getApt().mins << " with " << mechanics[Index].getName() << "." << endl;
		qCustomers.pop();
	}

	delete[] mechanics;
	delete[] customers; //freeing borrowed space from heap

	return 0;

}
