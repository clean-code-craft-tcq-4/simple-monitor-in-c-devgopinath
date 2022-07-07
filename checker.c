#include <stdio.h>
#include "checker.h"

float Temperature;
float StateOfCharge;
float ChargeRate;

int IsWithinLimit(float paramValue, float min, float max, char * paramName)
{
    if ((paramValue < min) || (paramValue > max))
    {
        char outMessage[50];
        sprintf(outMessage, "%s = %0.4f, out of range!\n", paramName, paramValue);
        printf("%s", outMessage);
        return NOT_IN_LIMIT;
    }
    else
    {
        return IN_LIMIT;
    }
}

int batteryIsOk(void)
{
    return (IS_TEMPERATURE_IN_LIMIT() &&
            IS_STATE_OF_CHARGE_IN_LIMIT() &&
            IS_CHARGE_RATE_IN_LIMIT());
}
