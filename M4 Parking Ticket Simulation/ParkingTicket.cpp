#include "ParkingTicket.h"
#include <cmath>

//Constructor
ParkingTicket::ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer, int minutesOver)
{
	//Copy car information
	year = car.getYear();
	make = car.getMake();
	model = car.getModel();
	color = car.getColor();
	plate = car.getLicensePlate();
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
		return 0.0; // No fine if not over time
	}
	double hours = ceil(minutesOver / 60.0); // Calculate hours, rounding up
	
	if (hours <= 1)
		return 25.0;

		return 25.0 + (hours - 1) * 10.0; // Base fine + $10 for each additional hour
	}
}