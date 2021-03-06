#include <stdio.h>
#include "checker.h"

float Temperature;
float StateOfCharge;
float ChargeRate;

float convertFarenheitToCelcius(float temp)
{
    return (temp - 32.0) * (5.0 / 9.0);
}

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

char WarningMessage[50];

void ReportWarningMessage(ParamLevel level, const ParamAttributes * param)
{
    sprintf(WarningMessage, "'%s' is in '%s' range!", param->paramName, WarningLevelMessage[level]);
    printf("%s\n", WarningMessage);
    return;
}

int IsWithinLimit(float paramValue, const ParamAttributes * param)
{
    if ((paramValue < param->min) || (paramValue > param->max))
    {
        char outMessage[50];
        sprintf(outMessage, "%s = %0.4f, out of range!", param->paramName, paramValue);
        printf("%s\n", outMessage);
        ReportWarningMessage(getOutLimitParamLevel(paramValue, param), param);
        return NOT_IN_LIMIT;
    }
    else
    {
        ReportWarningMessage(getInLimitParamLevel(paramValue, param), param);
        return IN_LIMIT;
    }
}

int batteryIsOk(void)
{
    return (IS_TEMPERATURE_IN_LIMIT() &&
            IS_STATE_OF_CHARGE_IN_LIMIT() &&
            IS_CHARGE_RATE_IN_LIMIT());
}

