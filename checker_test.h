#ifndef CHECKER_TEST_H
#define CHECKER_TEST_H

typedef struct
{
    float temperature;
    float stateOfCharge;
    float chargeRate;
    int expectedBattStatus;

} BatteryAttributes;

#define NO_OF_TESTCASES 8

extern const BatteryAttributes BatteryInputs[];

#endif
