#ifndef TEMPERATURE_BREACH_H
#define TEMPERATURE_BREACH_H

typedef enum {
  PassiveCooling,
  HiActiveCooling,
  MedActiveCooling
} CoolingType;

typedef enum {
  Normal,
  TooLow,
  TooHigh
} BreachType;

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

#endif // TEMPERATURE_BREACH_H
