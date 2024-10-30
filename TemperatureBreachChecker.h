#ifndef TEMPERATURE_BREACH_CHECKER_H
#define TEMPERATURE_BREACH_CHECKER_H

#define PASSIVE_COOLING_LOW 0
#define PASSIVE_COOLING_HIGH 35

#define HI_ACTIVE_COOLING_LOW 0
#define HI_ACTIVE_COOLING_HIGH 45

#define MED_ACTIVE_COOLING_LOW 0
#define MED_ACTIVE_COOLING_HIGH 40

typedef enum {
    PASSIVE_COOLING=0,
    HI_ACTIVE_COOLING=1,
    MED_ACTIVE_COOLING=2,
    NUM_COOLING_TYPES=3
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
