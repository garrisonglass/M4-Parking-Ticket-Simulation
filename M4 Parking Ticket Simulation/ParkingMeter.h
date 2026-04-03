#ifndef PARKINGMETER_H
#define PARKINGMETER_H

class ParkingMeter
{
	private:
		int minutesPurchased;

public:	
	//Constructor
	ParkingMeter(int minutesPurchased = 0);

	//Accessor
	int getMinutesPurchased() const { return minutesPurchased; }

};

#endif