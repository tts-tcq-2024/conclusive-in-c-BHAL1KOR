#include "TemperatureBreach.h"
#include "alert.h"

void CheckAndAlert(CoolingType coolingType, double temperatureInC, bool hasController) {
  BreachType breachType = ClassifyTemperatureBreach(coolingType, temperatureInC);
  if (hasController) {
    SendToController(breachType);
  } else {
    SendToEmail(breachType);
  }
}

int main() {
  CheckAndAlert(PassiveCooling, 50, true);
  CheckAndAlert(HiActiveCooling, 50, false);
  CheckAndAlert(MedActiveCooling, 50, true);
  return 0;
}
