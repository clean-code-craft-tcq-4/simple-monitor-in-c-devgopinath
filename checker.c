#include <stdio.h>
#include "checker.h"

float Temperature;
float StateOfCharge;
float ChargeRate;

int IsNotWithinLimit(float currentValue, float min, float max)
{
    return ((currentValue < min) || (currentValue > max));
}

int batteryIsOk(void)
{
    if(IS_TEMPERATURE_NOT_IN_LIMIT(Temperature))
    {
        printf("Temperature out of range!\n");
        return 0;
    }
    else if(IS_STATE_OF_CHARGE_NOT_IN_LIMIT(StateOfCharge))
    {
        printf("State of Charge out of range!\n");
        return 0;
    }
    else if(IS_CHARGE_RATE_NOT_IN_LIMIT(ChargeRate))
    {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}
