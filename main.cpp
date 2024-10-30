#include "TemperatureBreachChecker.h"
#include "TemperatureBreachAlerter.h"
#include <stdbool.h>
#include <stdio.h>



void CheckAndTemperatureBreachCheckAndAlert(CoolingType coolingType, double temperatureInC, bool hasController) {
  BreachType breachType = ClassifyTemperatureBreach(coolingType, temperatureInC);
   if (breachType != NORMAL) {
    printf("%d--%f***%d",coolingType, temperatureInC,breachType);
    void (*alertFunction)(BreachType) = hasController ? SendToController : SendToEmail;
    alertFunction(breachType);
  }
    else{
        printf("else case");
    }
}
