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

void unitTestTemperature(float temp, bool isInLimit)
{
    assert(IS_TEMPERATURE_IN_LIMIT(temp) == isInLimit);
}
void unitTestStateOfCharge(float soc, bool isInLimit)
{
    assert(IS_STATE_OF_CHARGE_IN_LIMIT(soc) == isInLimit);
}
void unitTestChargeRate(float chRate, bool isInLimit)
{
    assert(IS_STATE_OF_CHARGE_IN_LIMIT(soc) == isInLimit);
}

int main()
{
    for (int testCaseNo = 0; testCaseNo < NO_OF_TESTCASES; ++testCaseNo)
    {
        testBatteryStatus(testCaseNo);
    }

    unitTestTemperature(-0.1, false);
    unitTestTemperature(0.0, true);
    unitTestTemperature(20.0, true);
    unitTestTemperature(45.0, true);
    unitTestTemperature(45.1, false);

    unitTestStateOfCharge(19.9, false);
    unitTestStateOfCharge(20.0, true);
    unitTestStateOfCharge(40.0, true);
    unitTestStateOfCharge(80.0, true);
    unitTestStateOfCharge(80.1, false);

    unitTestChargeRate(0.0, true);
    unitTestChargeRate(0.4, true);
    unitTestChargeRate(0.75, true);
    unitTestChargeRate(0.8, true);
    unitTestChargeRate(0.85, false);
 
}
