#include "TemperatureBreachChecker.h"
#include "main.h"
#include <stdio.h>

CoolingTypeLimit coolingTypeLimits[NUM_COOLING_TYPES] = {
    {(double)PASSIVE_COOLING_LOW, (double)PASSIVE_COOLING_HIGH},  // PASSIVE_COOLING
    {(double)HI_ACTIVE_COOLING_LOW, (double)HI_ACTIVE_COOLING_HIGH},  // HI_ACTIVE_COOLING
    {(double)MED_ACTIVE_COOLING_LOW, (double)MED_ACTIVE_COOLING_HIGH}   // MED_ACTIVE_COOLING
};

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
   printf("cooling type = %d, coolingTypeLimits[coolingType].highLimit= %f", coolingType,coolingTypeLimits[coolingType].highLimit);
    printf("Comparing to %f, expe%f ",lowerLimit, value);
  printf("Comparing to h %f, expe%f ",upperLimit, value);
  return (temperatureInC < coolingTypeLimits[coolingType].lowLimit) ? TOO_LOW : (temperatureInC > coolingTypeLimits[coolingType].highLimit) ? TOO_HIGH : NORMAL;
  
}
