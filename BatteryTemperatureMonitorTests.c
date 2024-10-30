#include "TemperatureBreachChecker.h"
#include "TemperatureBreachAlerter.h"
#include <gtest/gtest.h>

void TestBreachCheckAndAlert(bool hasController, CoolingType coolingType, double temperature, const std::string& expectedOutput) {
    testing::internal::CaptureStdout();
    CheckAndTemperatureBreachCheckAndAlert(coolingType, temperature, hasController);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, expectedOutput);
}

TEST(TemperatureBreach, ControllerAlerts) {
    bool hasController = true;
    for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; ++coolingType) {
        TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit, ""); // Normal
        TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].lowLimit - 1, "feed : 1\n"); // TooLow
        TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit + 1, "feed : 2\n"); // TooHigh
    }

    hasController = false;
    for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; ++coolingType) {
        TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit, ""); // Normal
        TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].lowLimit - 1, "To: a.b@c.com\nHi, the temperature is too low\n"); // TooLow
        TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit + 1, "To: a.b@c.com\nHi, the temperature is too high\n"); // TooHigh
    }
}
