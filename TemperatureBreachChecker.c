#include "TemperatureBreachChecker.h"

BreachType InferBreach(double value, int lowerLimit, int upperLimit) {
  return (value < lowerLimit) ? TOO_LOW : (value > upperLimit) ? TOO_HIGH : NORMAL;
}

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    for (int i = 0; i < sizeof(coolingTypeLimits) / sizeof(coolingTypeLimits[0]); ++i) {
        if (coolingTypeLimits[i].type == coolingType) {
      return InferBreach(temperatureInC, coolingTypeLimits[i].lowLimit, coolingTypeLimits[i].highLimit);
    }
  }
  // Handle unexpected coolingType value
  return NORMAL;
}
