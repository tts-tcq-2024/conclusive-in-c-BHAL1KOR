#include "TemperatureBreachAlerter.h"
#include <stdio.h>

const int TO_CONTROLLER = 0xfeed;
const char* TO_EMAIL = "a.b@c.com";

void SendToController(BreachType breachType) {
  printf("%x : %x\n", TO_CONTROLLER, breachType);
}

void SendEmailAlert(const char* recepient, const char* message) {
  printf("To: %s\n", recepient);
  printf("%s\n", message);
}

void SendToEmail(BreachType breachType) {
  const char* recepient = TO_EMAIL;
  const char* message = NULL;

  if (breachType == TOO_LOW) {
    message = "Hi, the temperature is too low";
  } else {
    message = "Hi, the temperature is too high";
  }
  SendEmailAlert(recepient, message);
}
