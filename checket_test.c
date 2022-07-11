#include <stdio.h>
#include <assert.h>
#include "checker.h"
#include "checker_test.h"

void setTemperature(float temp)
{
    Temperature = temp;
}
void setStateOfCharge(float soc)
{
    StateOfCharge = soc;
}
void setChargeRate(float chRate)
{
    ChargeRate = chRate;
}

void testBatteryStatus(int testCaseNo)
{
    setTemperature(BatteryInputs[testCaseNo].temperature);
    setStateOfCharge(BatteryInputs[testCaseNo].stateOfCharge);
    setChargeRate(BatteryInputs[testCaseNo].chargeRate);

    assert(batteryIsOk() == BatteryInputs[testCaseNo].expectedBattStatus);
}

void unitTestTemperature(float temp, int isInLimit)
{
    setTemperature(temp);
    assert(IS_TEMPERATURE_IN_LIMIT() == isInLimit);
}
void unitTestStateOfCharge(float soc, int isInLimit)
{
    setStateOfCharge(soc);
    assert(IS_STATE_OF_CHARGE_IN_LIMIT() == isInLimit);
}
void unitTestChargeRate(float chRate, int isInLimit)
{
    setChargeRate(chRate);
    assert(IS_CHARGE_RATE_IN_LIMIT() == isInLimit);
}

void unitTestconvertFarenheitToCelcius(float temp_c, float temp_f)
{
    setTemperature(temp_f);
    assert(convertFarenheitToCelcius(temp_f) == temp_c);
}

void unitTestgetInLimitParamLevel(float paramValue, ParamLevel level)
{
    assert(getInLimitParamLevel(paramValue, &TestParamAttributes) == level);
}

int main()
{
    for (int testCaseNo = 0; testCaseNo < NO_OF_TESTCASES; ++testCaseNo)
    {
        testBatteryStatus(testCaseNo);
    }

    unitTestTemperature(-0.1, NOT_IN_LIMIT);
    unitTestTemperature(0.0, IN_LIMIT);
    unitTestTemperature(20.0, IN_LIMIT);
    unitTestTemperature(45.0, IN_LIMIT);
    unitTestTemperature(45.1, NOT_IN_LIMIT);

    unitTestStateOfCharge(19.9, NOT_IN_LIMIT);
    unitTestStateOfCharge(20.0, IN_LIMIT);
    unitTestStateOfCharge(40.0, IN_LIMIT);
    unitTestStateOfCharge(80.0, IN_LIMIT);
    unitTestStateOfCharge(80.1, NOT_IN_LIMIT);

    unitTestChargeRate(0.0, NOT_IN_LIMIT);
    unitTestChargeRate(0.1, IN_LIMIT);
    unitTestChargeRate(0.4, IN_LIMIT);
    unitTestChargeRate(0.75, IN_LIMIT);
    unitTestChargeRate(0.8, IN_LIMIT);
    unitTestChargeRate(0.85, NOT_IN_LIMIT);

    unitTestconvertFarenheitToCelcius(0.0, 32.0);
    unitTestconvertFarenheitToCelcius(45.0, 113.0);
    unitTestconvertFarenheitToCelcius(20.0, 68.0);
 
    // unitTestgetInLimitParamLevel(19.9, LOW_BREACH);
    unitTestgetInLimitParamLevel(20.0, LOW_WARNING);
    unitTestgetInLimitParamLevel(24.0, LOW_WARNING);
    unitTestgetInLimitParamLevel(24.1, NORMAL);
    unitTestgetInLimitParamLevel(50.0, NORMAL);
    unitTestgetInLimitParamLevel(75.9, NORMAL);
    unitTestgetInLimitParamLevel(76.0, HIGH_WARNING);
    unitTestgetInLimitParamLevel(80.0, HIGH_WARNING);
    // unitTestgetInLimitParamLevel(80.1, HIGH_BREACH);

}
