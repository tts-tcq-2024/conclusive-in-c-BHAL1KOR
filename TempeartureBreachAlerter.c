#include "TempeartureBreachAlerter.h"
#include <stdio.h>

const int TO_CONTROLLER = 0xfeed;
const char* TO_EMAIL = "a.b@c.com";

void SendToController(BreachType breachType) {
  printf("%x : %x\n", TO_CONTROLLER, breachType);
}

void SendToEmail(BreachType breachType) {
  const char* recepient = TO_EMAIL;
  switch(breachType) {
    case TooLow:
      printf("To: %s\nHi, the temperature is too low\n", recepient);
      break;
    case TooHigh:
      printf("To: %s\nHi, the temperature is too high\n", recepient);
      break;
    case Normal:
      break;
  }
}
