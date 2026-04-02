#include "ParkingTicket.h"
#include <cmath>

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
	fineAmount = calulateFine(minutesOver);
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
	out << "Parking Ticket:\n";
	out << "License Plate: " << ticket.plate << ", Year: " << ticket.year << ", Make: " << ticket.make 
		<< ", Model: " << ticket.model << ", Color: " << ticket.color << "\n";
	out << "Officer: " << ticket.officerName << ", Badge: " << ticket.badgeNumber << "\n";
	out << "Minutes Over: " << ticket.minutesOver << ", Fine Amount: $" << ticket.fineAmount;
	
	return out;
}
