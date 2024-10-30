#include "TemperatureBreachChecker.h"
#include "TemperatureBreachAlerter.h"

void CheckAndTemperatureBreachCheckAndAlert(CoolingType coolingType, double temperatureInC, bool hasController) {
  BreachType breachType = ClassifyTemperatureBreach(coolingType, temperatureInC);
  void (*alertFunction)(BreachType) = hasController ? SendToController : SendToEmail;

  if (breachType != NORMAL) {
    alertFunction(breachType);
  }
}
