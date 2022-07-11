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

void ReportWarningMessage(ParamLevel level, const ParamAttributes * param)
{
    char warnMessage[50];
    sprintf(outMessage, "%s parameter is in '%s' range!\n", param->paramName, WarningMessage[level]);
    printf("%s", warnMessage);
    return;
}

int IsWithinLimit(float paramValue, const ParamAttributes * param)
{
    if ((paramValue < param->min) || (paramValue > param->max))
    {
        char outMessage[50];
        sprintf(outMessage, "%s = %0.4f, out of range!\n", param->paramName, paramValue);
        printf("%s", outMessage);
        ReportWarningMessage(getOutLimitParamLevel(paramValue, param), param);
        return NOT_IN_LIMIT;
    }
    else
    {
        ReportWarningMessage(getOutLimitParamLevel(paramValue, param), param);
        return IN_LIMIT;
    }
}

int batteryIsOk(void)
{
    return (IS_TEMPERATURE_IN_LIMIT() &&
            IS_STATE_OF_CHARGE_IN_LIMIT() &&
            IS_CHARGE_RATE_IN_LIMIT());
}

