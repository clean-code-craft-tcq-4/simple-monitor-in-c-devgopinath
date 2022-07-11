#include <stdio.h>
#include "checker.h"

float Temperature;
float StateOfCharge;
float ChargeRate;

ParamLevel getInLimitParamLevel(float paramValue, const ParamAttributes * param)
{
    float tolerance = param->max * INLIMIT_TOLERANCE_PERCENTAGE;
    ParamLevel level;
    
    if (paramValue <= (param->min + tolerance))
    {
        level = LOW_WARNING;
    }
    else if (paramValue >= (param->max - tolerance))
    {
        level = HIGH_WARNING;
    }
    else
    {
        level = NORMAL;
    }
    return level;
}

ParamLevel getOutLimitParamLevel(float paramValue, const ParamAttributes * param)
{
    ParamLevel level;
    
    if (paramValue < (param->min))
    {
        level = LOW_BREACH;
    }
    else
    {
        level = HIGH_BREACH;
    }

    return level;
}

int IsWithinLimit(float paramValue, const ParamAttributes * param)
{
    char outMessage[50];
    ParamLevel level;
    if ((paramValue < param->min) || (paramValue > param->max))
    {
        sprintf(outMessage, "%s = %0.4f, out of range!\n", param->paramName, paramValue);
        printf("%s", outMessage);
        level = getOutLimitParamLevel(paramValue, param);
        return NOT_IN_LIMIT;
    }
    else
    {
        level = getInLimitParamLevel(paramValue, param);
        return IN_LIMIT;
    }
}

int batteryIsOk(void)
{
    return (IS_TEMPERATURE_IN_LIMIT() &&
            IS_STATE_OF_CHARGE_IN_LIMIT() &&
            IS_CHARGE_RATE_IN_LIMIT());
}

