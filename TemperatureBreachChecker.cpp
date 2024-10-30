#include "TemperatureBreachChecker.h"
#include "main.h"

BreachType InferBreach(double value, int lowerLimit, int upperLimit) {
  return (value < lowerLimit) ? TOO_LOW : (value > upperLimit) ? TOO_HIGH : NORMAL;
}

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; coolingType = (CoolingType)(coolingType + 1)) {
    return InferBreach(temperatureInC, coolingTypeLimits[coolingType].lowLimit, coolingTypeLimits[coolingType].highLimit);
  }
  // Handle unexpected coolingType value
  return NORMAL;
}
