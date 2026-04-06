#ifndef UTILITY_H
#define UTILITY_H

#include "ParkingTicket.h"

//Prints a ticket if one exists; otherwise reports no violation.
//Takes ownership of the ticket pointer and deletes it after printing.
void PrintTicket(ParkingTicket* ticket);

#endif

