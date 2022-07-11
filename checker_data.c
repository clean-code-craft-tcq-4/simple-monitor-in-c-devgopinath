#include "checker.h"

const ParamAttributes TempParamAttributes =
{
    "Temperature",
    TEMPERATURE_MAX,
    TEMPERATURE_MIN
};

const ParamAttributes SocParamAttributes =
{
    "Start of Charge",
    STATE_OF_CHARGE_MAX,
    STATE_OF_CHARGE_MIN
};

const ParamAttributes ChRateParamAttributes =
{
    "Charge Rate",
    CHARGE_RATE_MAX,
    CHARGE_RATE_MIN
};

/* inline with ParamLevel enumeration */
const * WarningMessage[] =
{
    "LOW BREACH",
    "LOW WARNING",
    "NORMAL",
    "HIGH WARNING",
    "HIGH BREACH"
};
