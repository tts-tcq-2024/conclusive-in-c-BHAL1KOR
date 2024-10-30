**Test Suite: TemperatureBreach**

**Test Case 1**: Controller Alerts for Normal Temperature
Given:
  The system has a controller.
  The cooling type is set to one of the following: PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING.
  The temperature is set to the high limit of the respective cooling type.

When:
  The CheckAndTemperatureBreachCheckAndAlert function is called.

Then:
  No alert should be sent.
  The output should be an empty string.

**Test Case 2:** Controller Alerts for Too Low Temperature
Given:
  The system has a controller.
  The cooling type is set to one of the following: PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING.
  The temperature is set to one unit below the low limit of the respective cooling type.

When:
  The CheckAndTemperatureBreachCheckAndAlert function is called.

Then:
  An alert should be sent to the controller indicating the temperature is too low.
  The output should be "feed : 1\n".

**Test Case 3**: Controller Alerts for Too High Temperature
Given:
  The system has a controller.
  The cooling type is set to one of the following: PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING.
  The temperature is set to one unit above the high limit of the respective cooling type.
  
When:
  The CheckAndTemperatureBreachCheckAndAlert function is called.

Then:
  An alert should be sent to the controller indicating the temperature is too high.
  The output should be "feed : 2\n".
  
**Test Case 4:** Email Alerts for Normal Temperature
Given:
  The system does not have a controller.
  The cooling type is set to one of the following: PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING.
  The temperature is set to the high limit of the respective cooling type.
  
When:
  The CheckAndTemperatureBreachCheckAndAlert function is called.
  
Then:
  No alert should be sent.
  The output should be an empty string.
  
**Test Case 5:** Email Alerts for Too Low Temperature
Given:
  The system does not have a controller.
  The cooling type is set to one of the following: PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING.
  The temperature is set to one unit below the low limit of the respective cooling type.
  
When:
  The CheckAndTemperatureBreachCheckAndAlert function is called.
  
Then:
  An email alert should be sent indicating the temperature is too low.
  The output should be "To: a.b@c.com\nHi, the temperature is too low\n".
  
**Test Case 6: **Email Alerts for Too High Temperature

Given:
  The system does not have a controller.
  The cooling type is set to one of the following: PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING.
  The temperature is set to one unit above the high limit of the respective cooling type.
  
When:
  The CheckAndTemperatureBreachCheckAndAlert function is called.
  
Then:
  An email alert should be sent indicating the temperature is too high.
  The output should be "To: a.b@c.com\nHi, the temperature is too high\n".
