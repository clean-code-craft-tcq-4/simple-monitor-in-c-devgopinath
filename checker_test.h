#ifndef CHECKER_TEST_H
#define CHECKER_TEST_H

typedef struct
{
    float temperature;
    float stateOfCharge;
    float chargeRate;
    int expectedBattStatus;

} BatteryAttributes;

#define IN_LIMIT    1
#define NOT_IN_LIMIT    0

#define NO_OF_TESTCASES 8

extern const BatteryAttributes BatteryInputs[];

#endif
