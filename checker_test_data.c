#include "checker.h"
#include "checker_test.h"

const BatteryAttributes BatteryInputs[NO_OF_TESTCASES] =
{
    // min limits
    {
        0.0,    //temperature
        20.0,   //stateOfCharge
        0.1,    //chargeRate
        1  //expectedBattStatus
    },
    // max limits
    {
        45.0,    //temperature
        80.0,   //stateOfCharge
        0.8,    //chargeRate
        1  //expectedBattStatus
    },
    // < min temp
    {
        -0.1,    //temperature
        50.0,   //stateOfCharge
        0.4,    //chargeRate
        0  //expectedBattStatus
    },
    // > max temp
    {
        45.1,    //temperature
        50.0,   //stateOfCharge
        0.4,    //chargeRate
        0  //expectedBattStatus
    },
    // < min soc
    {
        20.0,    //temperature
        19.9,   //stateOfCharge
        0.4,    //chargeRate
        0  //expectedBattStatus
    },
    // > max soc
    {
        20.0,    //temperature
        80.1,   //stateOfCharge
        0.4,    //chargeRate
        0  //expectedBattStatus
    },
    // < min chrate
    {
        20.0,    //temperature
        50.0,   //stateOfCharge
        0.0,    //chargeRate
        0  //expectedBattStatus
    },
    // > max chrate
    {
        20.0,    //temperature
        50.0,   //stateOfCharge
        0.85,    //chargeRate
        0  //expectedBattStatus
    }
};

#define TEST_PARAMETER_MAX 80.0
#define TEST_PARAMETER_MIN 20.0

const ParamAttributes TestParamAttributes =
{
    "Test Parameter",
    TEST_PARAMETER_MAX,
    TEST_PARAMETER_MIN
};