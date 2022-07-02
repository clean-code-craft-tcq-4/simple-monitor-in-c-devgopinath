#include <stdio.h>
#include <assert.h>
#include "checker.h"
#include "checker_test.h"

void testBatteryStatus(int testCaseNo)
{
    Temperature = BatteryInputs[testCaseNo].temperature;
    StateOfCharge = BatteryInputs[testCaseNo].stateOfCharge;
    ChargeRate = BatteryInputs[testCaseNo].chargeRate;
    assert(batteryIsOk() == BatteryInputs[testCaseNo].expectedBattStatus);
}

void unitTestTemperature(float temp, int isInLimit)
{
    assert(IS_TEMPERATURE_NOT_IN_LIMIT(temp) == isInLimit);
}
void unitTestStateOfCharge(float soc, int isInLimit)
{
    assert(IS_STATE_OF_CHARGE_NOT_IN_LIMIT(soc) == isInLimit);
}
void unitTestChargeRate(float chRate, int isInLimit)
{
    assert(IS_STATE_OF_CHARGE_NOT_IN_LIMIT(chRate) == isInLimit);
}

int main()
{
    for (int testCaseNo = 0; testCaseNo < NO_OF_TESTCASES; ++testCaseNo)
    {
        testBatteryStatus(testCaseNo);
    }

    unitTestTemperature(-0.1, 1);
    unitTestTemperature(0.0, 0);
    unitTestTemperature(20.0, 0);
    unitTestTemperature(45.0, 0);
    unitTestTemperature(45.1, 1);

    unitTestStateOfCharge(19.9, 1);
    unitTestStateOfCharge(20.0, 0);
    unitTestStateOfCharge(40.0, 0);
    unitTestStateOfCharge(80.0, 0);
    unitTestStateOfCharge(80.1, 1);

    unitTestChargeRate(0.0, 1);
    unitTestChargeRate(0.1, 0);
    unitTestChargeRate(0.4, 0);
    unitTestChargeRate(0.75, 0);
    unitTestChargeRate(0.8, 0);
    unitTestChargeRate(0.85, 1);
 
}
