#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>

using namespace std;

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
	
	//constructo
	ParkedCar(const string& year = "",
		      const string& make = "",
		      const string& model = "",
		      const string& color = "",
		      const string& plate = "",
		      int minutesParked = 0);
	
	//Accessors
	string getYear()    const { return year; }
	string getMake()    const { return make; }
	string getModel()   const { return model; }
	string getLicense() const { return plate; }
	string getColor()   const { return color; }
	int getMinutesParked() const { return minutesParked; }

};

#endif