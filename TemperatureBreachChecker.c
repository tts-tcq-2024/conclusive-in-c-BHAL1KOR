#include "TemperatureBreachChecker.h"

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  for (int i = 0; i < sizeof(coolingTypeLimits) / sizeof(coolingTypeLimits[0]); i++) {
    if (coolingTypeLimits[i].coolingType == coolingType) {
      return InferBreach(temperatureInC, coolingTypeLimits[i].lowerLimit, coolingTypeLimits[i].upperLimit);
    }
  }
  // Handle unexpected coolingType value
  return NORMAL;
}

BreachType InferBreach(double value, int lowerLimit, int upperLimit) {
  return (value < lowerLimit) ? TOO_LOW : (value > upperLimit) ? TOO_HIGH : NORMAL;
}
