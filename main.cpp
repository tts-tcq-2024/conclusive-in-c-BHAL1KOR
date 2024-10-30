#include "TemperatureBreachChecker.h"
#include "TemperatureBreachAlerter.h"
#include <stdbool.h>

CoolingTypeLimits coolingTypeLimits[] = {
    {PASSIVE_COOLING, PASSIVE_COOLING_LOW, PASSIVE_COOLING_HIGH},
    {HI_ACTIVE_COOLING, HI_ACTIVE_COOLING_LOW, HI_ACTIVE_COOLING_HIGH},
    {MED_ACTIVE_COOLING, MED_ACTIVE_COOLING_LOW, MED_ACTIVE_COOLING_HIGH}
};

void CheckAndTemperatureBreachCheckAndAlert(CoolingType coolingType, double temperatureInC, bool hasController) {
  BreachType breachType = ClassifyTemperatureBreach(coolingType, temperatureInC);
  void (*alertFunction)(BreachType) = hasController ? SendToController : SendToEmail;

  if (breachType != NORMAL) {
    alertFunction(breachType);
  }
}
