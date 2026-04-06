#ifndef MULTICAR_H
#define MULTICAR_H

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

//Inspects multiple cars using the same officer.
//Each car is paired with its corresponding parking meter.
void MultiCarLoop(PoliceOfficer& officer,
	              ParkedCar cars[],
	              ParkingMeter meters[],
	              int count);

#endif
