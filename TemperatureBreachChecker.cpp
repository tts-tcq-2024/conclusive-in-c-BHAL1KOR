#include "TemperatureBreachChecker.h"
#include "main.h"
#include <stdio.h>

CoolingTypeLimit coolingTypeLimits[NUM_COOLING_TYPES] = {
    {(double)PASSIVE_COOLING_LOW, (double)PASSIVE_COOLING_HIGH},  // PASSIVE_COOLING
    {(double)HI_ACTIVE_COOLING_LOW, (double)HI_ACTIVE_COOLING_HIGH},  // HI_ACTIVE_COOLING
    {(double)MED_ACTIVE_COOLING_LOW, (double)MED_ACTIVE_COOLING_HIGH}   // MED_ACTIVE_COOLING
};

BreachType InferBreach(double value, double lowerLimit, double upperLimit) {
  printf("Comparing to %f, expe%f ",lowerLimit, value);
  printf("Comparing to h %f, expe%f ",upperLimit, value);
  return (value < lowerLimit) ? TOO_LOW : (value > upperLimit) ? TOO_HIGH : NORMAL;
}

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; coolingType++) {
      printf("cooling type = %d, coolingTypeLimits[coolingType].highLimit= %f", coolingType,coolingTypeLimits[coolingType].highLimit);
    return InferBreach(temperatureInC, coolingTypeLimits[coolingType].lowLimit, coolingTypeLimits[coolingType].highLimit);
  }
  // Handle unexpected coolingType value
  return NORMAL;
}
