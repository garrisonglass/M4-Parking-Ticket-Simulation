// M4 Parking Ticket Simulation.cpp : This file contains the 'main' function, the test program for the Parking Ticket Simulation.
//

#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include "ParkingTicket.h"
#include "PrintTicket.h"

using namespace std;

//void printTicketResult(ParkingTicket* ticket);

int main()
{
    cout << "Parking Ticket test\n\n";

	//Creat Police Officer
	PoliceOfficer officer("John Smith", "12345");

	//Test 1: No Violation
	cout << "Test 1: No Violation\n";

	ParkedCar car1("2020", "Toyota", "C-HR", "White", "ABC123", 30); //Parked for 30 minutes
	ParkingMeter meter1(60); //Purchased 60 minutes

	ParkingTicket* ticket1 = officer.inspect(car1, meter1);

	//if (ticket1 == nullptr)
	//{
	//	cout << "No violation. No ticket issued.\n\n";
	//}
	//else
	//{
	//	cout << *ticket1 << "\n\n";
	//	delete ticket1; //Clean up
	//}
	//return 0;
	PrintTicket(ticket1);

	//Test 2: Small violation (10 minutes over)
	cout << "Test 2: Small Violation\n\n";

	ParkedCar car2("2020", "Honda", "Civic", "Black", "123ABC", 70);//Parked 10 minutes over the limet
	ParkingMeter meter2(60);//Purchased 60 minutes

	ParkingTicket* ticket2 = officer.inspect(car2, meter2);

	PrintTicket(ticket2);

}

//void printTicketResult(ParkingTicket* ticket)
//{
//	if (ticket == nullptr)
//	{
//		cout << "No violation detected.\n\n";
//	}
//	else
//	{
//		cout << *ticket << "\n\n";
//		delete ticket; // Clean up memory
//	}
//}
//
