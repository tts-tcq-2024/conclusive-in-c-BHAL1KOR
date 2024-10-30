#ifndef ALERT_H
#define ALERT_H
#include "TemperatureBreachChecker.h"

void SendToController(BreachType breachType);
void SendToEmail(BreachType breachType);

#endif // ALERT_H
