#include <fstream>
#include <iostream>
using namespace std;
#include "customer.h"
#include "mechanic.h"
#include "queuec.h"

const int MAX_MECHANICS = 3;
const int MAX_CUSTOMERS = 4;

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

	if (customersInput.fail()){ //checking if file is open
		cout << "failed to open file 2" << endl;
		exit(1);
	}

	int numCustomers;

	customersInput >> numCustomers;
	customer* customers = new customer[numCustomers];

	for (int i = 0; i < numCustomers; i ++)
	{
		string name;
		int age, id, h, m;
		customersInput >> name >> id >> age >> h >> m;
		customers[i] = customer(name, id, age, appointment(h, m), -1); //declaring an array of customers with unassigned mechanics
	}
	customersInput.close();

	// Read mechanics' data from the user or initialize them within the main function
	/*mechanic mechanics[MAX_MECHANICS];
	mechanics[0].setName("Ayman");
	mechanics[1].setName("Khaled");
	mechanics[2].setName("Jana");*/

	// Read customers' data from the user
	/*customer customers[MAX_CUSTOMERS];
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
	customers[3].setID(4);*/




	Queue<customer> qCustomers(numCustomers);
	//checking availability
	for (int j = 0; j < numCustomers;j++)
	{
		bool foundMech = false;
		for (int i = 0; i < mechAmount;i++)
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
		if(customers[i].getmID()!= -1)
		qCustomers.push(customers[i]);
	}

	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		cout << qCustomers.peek().getName() << " has an appointment at " << qCustomers.peek().getApt().hours << ":" << qCustomers.peek().getApt().mins << " with " << mechanics[i].getName() << "." << endl;
		qCustomers.pop();
	}

	delete[] mechanics;
	delete[] customers; //freeing borrowed space from heap

	return 0;

}