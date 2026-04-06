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

//Test driver for the Parking Ticket Simulation.
//Demonstrates legal parking, violations, fine calculation,
//and multi-car inspection.

int main()
{
    cout << "Parking Ticket test\n\n";

	//Creat Police Officer for all inspections
	PoliceOfficer officer("John Smith", "12345");

	//Test 1: No Violation
	cout << "Test 1: No Violation\n";

	ParkedCar car1("2020", "Toyota", "C-HR", "White", "ABC123", 30);//Parked for 30 minutes
	ParkingMeter meter1(60);//Purchased 60 minutes
    ParkingTicket* ticket1 = officer.inspect(car1, meter1);
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
		ParkedCar("2018", "Subaru", "Outback", "Silver", "VAZ271", 30),//No violation
		ParkedCar("2019", "Nissan", "Altima", "Blue", "KQH552", 90),//Small violation
		ParkedCar("2022", "Dodge", "Charger", "Orange", "RXT904", 150),//Large violation
		ParkedCar("1969", "Pontiac", "GTO", "Green", "MUSCLE1", 181)//Edge case
	};

	ParkingMeter meters[] = {
		ParkingMeter(60),//Car 1
		ParkingMeter(60),//Car 2
		ParkingMeter(60),//Car 3
		ParkingMeter(60) //Car 4
	};

	MultiCarLoop(officer, cars, meters, 4);

	return 0;

}

