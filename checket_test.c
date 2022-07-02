#include <stdio.h>
#include <assert.h>
#include "checker.h"
#include "checker_test.h"

int no_of_testcases = NO_OF_TESTCASES;

void testBatteryStatus(int testCaseNo)
{
    Temperature = BatteryInputs[testCaseNo].temperature;
    StateOfCharge = BatteryInputs[testCaseNo].stateOfCharge;
    ChargeRate = BatteryInputs[testCaseNo].chargeRate;
    assert(batteryIsOk() == BatteryInputs[testCaseNo].expectedBattStatus);
}

void unitTestTemperature(float temp, int isInLimit)
{
    assert(IS_TEMPERATURE_IN_LIMIT(temp) == isInLimit);
}
void unitTestStateOfCharge(float soc, int isInLimit)
{
    assert(IS_STATE_OF_CHARGE_IN_LIMIT(soc) == isInLimit);
}
void unitTestChargeRate(float chRate, int isInLimit)
{
    assert(IS_STATE_OF_CHARGE_IN_LIMIT(chRate) == isInLimit);
}

int main()
{
    for (int testCaseNo = 0; testCaseNo < no_of_testcases; ++testCaseNo)
    {
        testBatteryStatus(testCaseNo);
    }

    unitTestTemperature(-0.1, 0);
    unitTestTemperature(0.0, 1);
    unitTestTemperature(20.0, 1);
    unitTestTemperature(45.0, 1);
    unitTestTemperature(45.1, 0);

    unitTestStateOfCharge(19.9, 0);
    unitTestStateOfCharge(20.0, 1);
    unitTestStateOfCharge(40.0, 1);
    unitTestStateOfCharge(80.0, 1);
    unitTestStateOfCharge(80.1, 0);

    unitTestChargeRate(0.0, 1);
    unitTestChargeRate(0.4, 1);
    unitTestChargeRate(0.75, 1);
    unitTestChargeRate(0.8, 1);
    unitTestChargeRate(0.85, 0);
 
}
