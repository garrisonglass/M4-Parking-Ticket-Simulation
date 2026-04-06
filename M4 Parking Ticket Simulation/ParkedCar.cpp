#include "ParkedCar.h"

//Initializes a ParkedCar with descriptive information and parked duration.

ParkedCar::ParkedCar(const string& year, 
	                 const string& make, 
	                 const string& model, 
	                 const string& color, 
	                 const string& plate, 
	                 int minutesParked)
{
	this->year  = year;
	this->make  = make;
	this->model = model;
	this->color = color;
	this->plate = plate;
	this->minutesParked = minutesParked;
}
