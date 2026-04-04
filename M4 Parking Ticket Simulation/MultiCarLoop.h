#ifndef MULTICAR_H
#define MULTICAR_H

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

void MultiCarLoop(PoliceOfficer& officer,
	              ParkedCar cars[],
	              ParkingMeter meters[],
	              int count);

#endif
