#include "MultiCarLoop.h"
#include <iostream>
#include "PrintTicket.h"

using namespace std;

void MultiCarLoop(PoliceOfficer& officer, 
	              ParkedCar cars[], 
	              ParkingMeter meters[], 
	              int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Inspecting Car " << (i + 1) << ":\n";
		ParkingTicket* ticket = officer.inspect(cars[i], meters[i]);
		PrintTicket(ticket);
	}
}
