#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
#include <ParkedCar.h>
#include <ParkingMeter.h>
#include <ParkingTicket>

using namespace std;

class PoliceOfficer
{
private:
	string name;
    string badgeNumber;

public:
	//Constructor
	PoliceOfficer(const string& officerName = "", const string& badge = "");

	//Accessor functions
	string getName() const;
	string getBadgeNumber() const;

	//Inspects the parked car and parking meter, and returns a pointer to a ParkingTicket
	//if the car is in violation, or nullptr if there is no violation.
	ParkingTicket* inspect(const ParkedCar& car, const ParkingMeter& meter) const;

};

#endif 