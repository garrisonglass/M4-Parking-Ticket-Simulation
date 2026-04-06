//PtintTicket.cpp
#include "PrintTicket.h"
#include <iostream>

using namespace std;

//Displays ticket information or reports no violation.
//Deletes the ticket afterward to prevent memory leaks.
void PrintTicket(ParkingTicket* ticket)
{
	if (ticket == nullptr)
	{
		cout << "No violation detected.\n\n";
	}
	else
	{
		cout << *ticket << "\n\n";
		delete ticket; //Clean up memory
	}
}
