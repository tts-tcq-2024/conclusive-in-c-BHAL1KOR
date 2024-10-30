#include "TemperatureBreach.h"

BreachType InferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TooLow;
  }
  if(value > upperLimit) {
    return TooHigh;
  }
  return Normal;
}

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  
  switch(coolingType) {
    case PassiveCooling:
      upperLimit = 35;
      break;
    case HiActiveCooling:
      upperLimit = 45;
      break;
    case MedActiveCooling:
      upperLimit = 40;
      break;
  }
  return InferBreach(temperatureInC, lowerLimit, upperLimit);
}
