#include "PrintTicket.h"
#include <iostream>

using namespace std;

void PrintTicket(ParkingTicket* ticket)
{
	if (ticket == nullptr)
	{
		cout << "No violation detected.\n\n";
	}
	else
	{
		cout << *ticket << "\n\n";
		delete ticket; // Clean up memory
	}
}
