#ifndef MAIN_H
#define MAIN_H

#include "TemperatureBreachChecker.h" // Include the necessary header for CoolingType
#include <stdbool.h>

void CheckAndTemperatureBreachCheckAndAlert(CoolingType coolingType, double temperatureInC, bool hasController);

#endif // MAIN_H
