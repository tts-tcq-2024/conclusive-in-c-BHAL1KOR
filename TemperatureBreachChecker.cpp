#include "TemperatureBreachChecker.h"
#include "main.h"
#include <stdio.h>
BreachType InferBreach(double value, int lowerLimit, int upperLimit) {
  return (value < lowerLimit) ? TOO_LOW : (value > upperLimit) ? TOO_HIGH : NORMAL;
}

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  printf("here got %d, %f", coolingType, temperatureInC);
  for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; coolingType = (CoolingType)(coolingType + 1)) {
    printf("got output %d\n', InferBreach(temperatureInC, coolingTypeLimits[coolingType].lowLimit, coolingTypeLimits[coolingType].highLimit));
    return InferBreach(temperatureInC, coolingTypeLimits[coolingType].lowLimit, coolingTypeLimits[coolingType].highLimit);
  }
  // Handle unexpected coolingType value
  return NORMAL;
}
