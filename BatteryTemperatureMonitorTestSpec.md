## Test Cases for Temperature Breach Alerts

### Common Setup
Given:
  - The system may or may not have a controller.
  - The cooling type is set to one of the following: PASSIVE_COOLING, HI_ACTIVE_COOLING, MED_ACTIVE_COOLING.

### Test Case 1: No Alert for Normal Temperature
Given:
  - The temperature is set to the high limit of the respective cooling type.
  
When:
  - The CheckAndTemperatureBreachCheckAndAlert function is called.
  
Then:
  - No alert should be sent.
  - The output should be an empty string.

### Test Case 2: Alerts for Too Low Temperature
Given:
  - The temperature is set to one unit below the low limit of the respective cooling type.
  
When:
  - The CheckAndTemperatureBreachCheckAndAlert function is called.
  
Then:
  - If the system has a controller, the output should be "feed : 1\n".
  - If the system does not have a controller, the output should be "To: a.b@c.com\nHi, the temperature is too low\n".

### Test Case 3: Alerts for Too High Temperature
Given:
  - The temperature is set to one unit above the high limit of the respective cooling type.
  
When:
  - The CheckAndTemperatureBreachCheckAndAlert function is called.
  
Then:
  - If the system has a controller, the output should be "feed : 2\n".
  - If the system does not have a controller, the output should be "To: a.b@c.com\nHi, the temperature is too high\n".
