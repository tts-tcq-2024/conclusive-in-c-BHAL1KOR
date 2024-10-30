#include <gtest/gtest.h>
#include "main.h"
#include <stdbool.h>

void TestBreachCheckAndAlert(bool hasController, CoolingType coolingType, double temperature, const std::string& expectedOutput) {
    testing::internal::CaptureStdout();
    CheckAndTemperatureBreachCheckAndAlert(coolingType, temperature, hasController);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, expectedOutput);
}

// Helper function to generate controller message
std::string GetControllerMessage(bool isTooLow) {
    return isTooLow ? "feed : 1\n" : "feed : 2\n";
}

// Helper function to generate email message
std::string GetEmailMessage(bool isTooLow) {
    return isTooLow ? "To: a.b@c.com\nHi, the temperature is too low\n" : "To: a.b@c.com\nHi, the temperature is too high\n";
}

// Main function to get alert message
std::string GetAlertMessage(bool hasController, bool isTooLow) {
    return hasController ? GetControllerMessage(isTooLow) : GetEmailMessage(isTooLow);
}
void RunTestCases(bool hasController, CoolingType coolingType) {
    const char* tooLowAlert = GetAlertMessage(hasController, true).c_str();
    const char* tooHighAlert = GetAlertMessage(hasController, false).c_str();

    TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit, ""); // Normal
    TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].lowLimit - 1, tooLowAlert); // TooLow
    TestBreachCheckAndAlert(hasController, coolingType, coolingTypeLimits[coolingType].highLimit + 1, tooHighAlert); // TooHigh
}

TEST(TemperatureBreach, Alerts) {
    for (bool hasController : {true, false}) {
        for (CoolingType coolingType = PASSIVE_COOLING; coolingType <= MED_ACTIVE_COOLING; coolingType = (CoolingType)(coolingType + 1)) {
            RunTestCases(hasController, coolingType);
        }
    }
}
