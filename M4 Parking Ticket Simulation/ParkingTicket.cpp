#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <cmath>
#include <ostream>
#include <iomanip>

using namespace std;
//Constructor
ParkingTicket::ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer, int minutesOver)
{
	//Copy car information
	year = car.getYear();
	make = car.getMake();
	model = car.getModel();
	color = car.getColor();
	plate = car.getLicense();
	//Copy officer information
	officerName = officer.getName();
	badgeNumber = officer.getBadgeNumber();
	//Set violation details
	this->minutesOver = minutesOver;
	fineAmount = calculateFine(minutesOver);
}

//Fine calculation
double ParkingTicket::calculateFine(int minutesOver) const
{
	if (minutesOver <= 0)
	{
		return 0.0; //No fine if not over time
	}
	double hours = ceil(minutesOver / 60.0); //Calculate hours, rounding up
	
	if (hours <= 1)
		return 25.0;

	return 25.0 + (hours - 1) * 10.0; //Base fine + $10 for each additional hour
	
}

ostream& operator<<(ostream& out, const ParkingTicket& ticket)
{
	out << "-------- Parking Ticket ---------\n\n";
	out << "Officer: " << ticket.officerName << ", Badge# " << ticket.badgeNumber << "\n\n";
	out << "------ Vehicle Information ------\n\n";
	out << left << setw(5) << "License Plate: " << ticket.plate << "\n";
	out << left << setw(15) << "Year: " << ticket.year << "\n";
	out << left << setw(15) << "Make: " << ticket.make << "\n";
	out << left << setw(15) << "Model: " << ticket.model << "\n";
	out << left << setw(15) << "Color: " << ticket.color << "\n\n";
	out << "------- Violation Details -------\n\n";
	out << left << setw(15) << "Minutes Over: " << ticket.minutesOver << "\n";
	out << left << setw(15) << "Fine:" << "$" << ticket.fineAmount;
	
	return out;
}
