#ifndef PARKINGMETER_H
#define PARKINGMETER_H

//Represents a parking meter that tracks purchased parking time.
class ParkingMeter
{
	private:
		int minutesPurchased;

public:	
	//Constructs a ParkingMeter with the number of minutes purchased.
	ParkingMeter(int minutesPurchased = 0);

	//Returns the amount of purchased parking time.
	int getMinutesPurchased() const { return minutesPurchased; }

};

#endif