#include "TemperatureBreachChecker.h"
#include "main.h"

CoolingTypeLimit coolingTypeLimits[] = {
    {(double)PASSIVE_COOLING_LOW, (double)PASSIVE_COOLING_HIGH},  
    {(double)HI_ACTIVE_COOLING_LOW, (double)HI_ACTIVE_COOLING_HIGH},  
    {(double)MED_ACTIVE_COOLING_LOW, (double)MED_ACTIVE_COOLING_HIGH}   
};

BreachType ClassifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  return (temperatureInC < coolingTypeLimits[coolingType].lowLimit) ? TOO_LOW : (temperatureInC > coolingTypeLimits[coolingType].highLimit) ? TOO_HIGH : NORMAL;
}
