// M4 Parking Ticket Simulation.cpp : This file contains the 'main' function, the test program for the Parking Ticket Simulation.
//

#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include "ParkingTicket.h"
#include "PrintTicket.h"
#include "MultiCarLoop.h"

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

	//Test 3: Large violation (119 minutes over)
	ParkedCar car3("2024", "Ford", "Mustang", "Red", "XYZ789", 179);//Parked 119 minutes over the limit
	ParkingMeter meter3(60);//Purchased 60 minutes

	ParkingTicket* ticket3 = officer.inspect(car3, meter3);

	PrintTicket(ticket3);

	//Test 4: Edge case (1 min past 2 hours over, 121 minutes)
	ParkedCar car4("1973", "Chevrolet", "Corvette", "White", "LS454", 181);//Parked 121 minutes over the limit
	ParkingMeter meter4(60);//Purchased 60 minutes

	ParkingTicket* ticket4 = officer.inspect(car4, meter4);

	PrintTicket(ticket4);

	//Test 5: Multiple cars loop
	cout << "Test 5: Multiple Cars Loop\n\n";
	

	ParkedCar cars[] = {
		ParkedCar("2020", "Toyota", "C-HR", "White", "ABC123", 30), //No violation
		ParkedCar("2020", "Honda", "Civic", "Black", "123ABC", 70), //Small violation
		ParkedCar("2024", "Ford", "Mustang", "Red", "XYZ789", 179), //Large violation
		ParkedCar("1973", "Chevrolet", "Corvette", "White", "LS454", 181) //Edge case
	};

	ParkingMeter meters[] = {
		ParkingMeter(60), //Car 1
		ParkingMeter(60), //Car 2
		ParkingMeter(60), //Car 3
		ParkingMeter(60)  //Car 4
	};

	MultiCarLoop(officer, cars, meters, 4);

	return 0;

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
