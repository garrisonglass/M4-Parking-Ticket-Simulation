#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>

using namespace std;

//Represents a vehicle parked in a metered space.
//Stores identifying details and how long the car has been parked.

class ParkedCar

{

private:
	
	string year;
	string make;
	string model;
	string color;
	string plate;
	int minutesParked;

public:
	
	//Constructs a ParkedCar with descriptive information and parked duration.
	ParkedCar(const string& year = "",
		      const string& make = "",
		      const string& model = "",
		      const string& color = "",
		      const string& plate = "",
		      int minutesParked = 0);
	
	//Accessors for car details and parked time.
	string getYear()    const { return year; }
	string getMake()    const { return make; }
	string getModel()   const { return model; }
	string getColor()   const { return color; }
	string getLicense() const { return plate; }
	int getMinutesParked() const { return minutesParked; }

};

#endif