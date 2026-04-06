#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
#include "ParkedCar.h"
#include "ParkingMeter.h"

class ParkingTicket;


using namespace std;

//Represents a police officer responsible for inspecting parked cars.
class PoliceOfficer
{
private:
	string name;
    string badgeNumber;

public:
	//Constructs an officer with a name and badge number.
	PoliceOfficer(const string& officerName = "", const string& badge = "");

	//Accessor for officer identity
	string getName() const { return name; }
	string getBadgeNumber() const { return badgeNumber; }

	//Inspects the parked car and parking meter, and returns a pointer to a ParkingTicket
	//if the car is in violation, or nullptr if there is no violation.
	ParkingTicket* inspect(const ParkedCar& car, const ParkingMeter& meter) const;

};

#endif 