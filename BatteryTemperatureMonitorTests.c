#include "temperature_breach.h"
#include "alert.h"
#include <gtest/gtest.h>

TEST(TemperatureBreach, InfersBreachAsPerLimits) {
  ASSERT_EQ(InferBreach(12, 20, 30), TooLow);
  ASSERT_EQ(InferBreach(35, 20, 30), TooHigh);
  ASSERT_EQ(InferBreach(25, 20, 30), Normal);
}

TEST(TemperatureBreach, ClassifiesTemperatureBreach) {
  ASSERT_EQ(ClassifyTemperatureBreach(PassiveCooling, 50), TooHigh);
  ASSERT_EQ(ClassifyTemperatureBreach(HiActiveCooling, 50), Normal);
  ASSERT_EQ(ClassifyTemperatureBreach(MedActiveCooling, 50), TooHigh);
}

TEST(Alert, SendsToController) {
  testing::internal::CaptureStdout();
  SendToController(TooLow);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "feed : 1\n");
}

TEST(Alert, SendsToEmail) {
  testing::internal::CaptureStdout();
  SendToEmail(TooLow);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "To: a.b@c.com\nHi, the temperature is too low\n");
}

TEST(Main, CheckAndAlertWithController) {
  testing::internal::CaptureStdout();
  CheckAndAlert(PassiveCooling, 50, true);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "feed : 2\n");
}

TEST(Main, CheckAndAlertWithoutController) {
  testing::internal::CaptureStdout();
  CheckAndAlert(HiActiveCooling, 50, false);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_EQ(output, "To: a.b@c.com\nHi, the temperature is too high\n");
}
