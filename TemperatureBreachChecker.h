#ifndef TEMPERATURE_BREACH_CHECKER_H
#define TEMPERATURE_BREACH_CHECKER_H

#define PASSIVE_COOLING_LOW 0
#define PASSIVE_COOLING_HIGH 35

#define HI_ACTIVE_COOLING_LOW 0
#define HI_ACTIVE_COOLING_HIGH 45

#define MED_ACTIVE_COOLING_LOW 0
#define MED_ACTIVE_COOLING_HIGH 40

typedef enum {
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING
} CoolingType;

typedef struct {
    double lowLimit;
    double highLimit;
} CoolingTypeLimit;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperature);

#endif // TEMPERATURE_BREACH_CHECKER_H
