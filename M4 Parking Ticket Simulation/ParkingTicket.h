#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include "ParkedCar.h"
#include "PoliceOfficer.h"
#include <string>
#include <iostream>

using namespace std;
class ParkingTicket
{
	private:
		//CAr information
		string year;
		string make;
		string model;
		string color;
		string plate;

		//Officer information
		string officerName;
		string badgeNumber;

		//Violation details
		int   minutesOver;
		double fineAmount;

		//Fine calculation constants
		double calulateFine(int minutesOver) const;

	public:
		//Constructor
		ParkingTicket(const ParkedCar& car, const PoliceOfficer& officer, int minutesOver);
		
		//Accessor functions	
		double genFine()     const { return fineAmount; }
		int getMinutesOver() const { return minutesOver; }

		friend ostream& operator<<(ostream& out, const ParkingTicket& ticket);
};

#endif