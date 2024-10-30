#include "TemperatureBreachChecker.h"
#include "main.h"
#include <stdio.h>
BreachType InferBreach(double value, int lowerLimit, int upperLimit) {
  printf("Comparing to %d, expe%d",lowerLimit, value);
  printf("Comparing to h %d, expe%d",upperLimit, value);
  return (value < lowerLimit) ? TOO_LOW : (value > upperLimit) ? TOO_HIGH : NORMAL;
}

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; coolingType = (CoolingType)(coolingType + 1)) {
    return InferBreach(temperatureInC, coolingTypeLimits[coolingType].lowLimit, coolingTypeLimits[coolingType].highLimit);
  }
  // Handle unexpected coolingType value
  return NORMAL;
}
