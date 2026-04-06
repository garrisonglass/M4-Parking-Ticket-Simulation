#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include "ParkedCar.h"
#include <string>
#include <iostream>

class PoliceOfficer;

using namespace std;
//Represents a parking violation ticket issued by an officer.
//Stores car details, officer details, violation duration, and fine amount.
class ParkingTicket
{
	private:
		//CAr information copied from the ispected car
		string year;
		string make;
		string model;
		string color;
		string plate;

		//Officer information copied from the inspecting officer
		string officerName;
		string badgeNumber;

		//Violation details
		int   minutesOver;
		double fineAmount;

		//Calculates the fine based on the number of minutes over the purchased time.
		double calculateFine(int minutesOver) const;

	public:
		//Constructs a ParkingTicket using car and officer data.
		ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer, int minutesOver);
		
		//Accessors for fine and violation duration.
		double genFine()     const { return fineAmount; }
		int getMinutesOver() const { return minutesOver; }
		
		//Outputs formatted ticket information.
		friend ostream& operator<<(ostream& out, const ParkingTicket& ticket);
};

#endif