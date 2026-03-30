#include "PoliceOfficer.h"
using namespace std;

//Constructor
PoliceOfficer::PoliceOfficer(const string& officerName, const string& badge)
{
	name = officerName;
	badgeNumber = badge;
}

//Inspect a parked car and parking meter, and return a pointer to a ParkingTicket
//if the car is in violation, or nullptr if there is no violation.

ParkingTicket* PoliceOfficer::inspect(const ParkedCar& car, const ParkingMeter& meter) const
{
	int parked = car.getMinutesParked();
	int purchased = meter.getMinutesPurchased();

	if (parked > purchased)
	{
		//Violation exists - create and return a new ParkingTicket
		return new ParkingTicket(car, *this, parked - purchased);
	}
	else
	{
		//No violation - return nullptr
		return nullptr;
	}
}

