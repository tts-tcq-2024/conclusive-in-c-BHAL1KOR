#ifndef MAIN_H
#define MAIN_H

#include "TemperatureBreachChecker.h" // Include the necessary header for CoolingType

extern CoolingTypeLimits coolingTypeLimits[];
void CheckAndTemperatureBreachCheckAndAlert(CoolingType coolingType, double temperatureInC, bool hasController);

#endif // MAIN_H
