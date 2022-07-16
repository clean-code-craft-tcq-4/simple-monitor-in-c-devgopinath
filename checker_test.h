#ifndef CHECKER_TEST_H
#define CHECKER_TEST_H

typedef struct
{
    float temperature;
    float stateOfCharge;
    float chargeRate;
    int expectedBattStatus;

} BatteryAttributes;

#define NO_OF_TESTCASES (No_Of_TestCases)

extern const BatteryAttributes BatteryInputs[];
extern const int No_Of_TestCases;
extern const ParamAttributes TestParamAttributes;

#endif
