#include "TemperatureBreachChecker.h"
#include "TemperatureBreachAlerter.h"
#include <stdbool.h>

void CheckAndTemperatureBreachCheckAndAlert(CoolingType coolingType, double temperatureInC, bool hasController) {
  BreachType breachType = ClassifyTemperatureBreach(coolingType, temperatureInC);
   if (breachType != NORMAL) {
    void (*alertFunction)(BreachType) = hasController ? SendToController : SendToEmail;
    alertFunction(breachType);
  }
}
