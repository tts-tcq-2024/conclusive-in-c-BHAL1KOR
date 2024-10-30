#include "TemperatureBreachChecker.h"
#include "TemperatureBreachAlerter.h"
#include <gtest/gtest.h>
#include <stdbool.h>

void TestBreachCheckAndAlert(bool hasController, CoolingType coolingType, double temperature, const std::string& expectedOutput) {
    testing::internal::CaptureStdout();
    CheckAndTemperatureBreachCheckAndAlert(coolingType, temperature, hasController);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, expectedOutput);
}

TEST(TemperatureBreach, Alerts) {
    for (bool hasController : {true, false}) {
        for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; ++coolingType) {
            const char* tooLowAlert = hasController ? "feed : 1\n" : "To: a.b@c.com\nHi, the temperature is too low\n";
            const char* tooHighAlert = hasController ? "feed : 2\n" : "To: a.b@c.com\nHi, the temperature is too high\n";

            TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit, ""); // Normal
            TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].lowLimit - 1, tooLowAlert); // TooLow
            TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit + 1, tooHighAlert); // TooHigh
        }
    }
}
