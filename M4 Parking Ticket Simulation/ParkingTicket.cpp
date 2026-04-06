#include "ParkingTicket.h"
#include "PoliceOfficer.h"
#include <cmath>
#include <ostream>
#include <iomanip>

using namespace std;
//Initializes a ParkingTicket by copying car and officer details
//and calculating the fine based on the violation duration.
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
	double hours = ceil(minutesOver / 60.0);//Calculate hours, rounding up
	
	if (hours <= 1)
		return 25.0;

	return 25.0 + (hours - 1) * 10.0;//Base fine + $10 for each additional hour
	
}

//Outputs formatted ticket information for display.
ostream& operator<<(ostream& out, const ParkingTicket& ticket)
{
	const int width = 15; //Width for 
	out << "-------- Parking Ticket ---------\n\n";
	out << "Officer: " << ticket.officerName << ", Badge# " << ticket.badgeNumber << "\n\n";
	out << "------ Vehicle Information ------\n\n";
	out << left << setw(width) << "License Plate: " << ticket.plate << "\n";
	out << left << setw(width) << "Year: " << ticket.year << "\n";
	out << left << setw(width) << "Make: " << ticket.make << "\n";
	out << left << setw(width) << "Model: " << ticket.model << "\n";
	out << left << setw(width) << "Color: " << ticket.color << "\n\n";
	out << "------- Violation Details -------\n\n";
	out << left << setw(width) << "Minutes Over: " << ticket.minutesOver << "\n";
	out << left << setw(width) << "Fine:" << "$" << ticket.fineAmount;
	out << "\n\n---------------------------------\n\n";
	
	return out;
}
