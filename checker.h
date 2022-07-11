
#ifndef CHECKER_H
#define CHECKER_H

typedef struct
{
    char * paramName;
    float max;
    float min;
    
} ParamAttributes;

typedef enum
{
    LOW_BREACH = 0,
    LOW_WARNING,
    NORMAL,
    HIGH_WARNING,
    HIGH_BREACH
} ParamLevel;

//#define TEMPERATURE_IN_FARENHEIT

#ifdef TEMPERATURE_IN_FARENHEIT
#define GET_TEMPERATURE_IN_C(parameter) convertFarenheitToCelcius(parameter)
#else
#define GET_TEMPERATURE_IN_C(parameter) (parameter)
#endif

#define TEMPERATURE_MIN 0.0
#define TEMPERATURE_MAX 45.0
#define IS_TEMPERATURE_IN_LIMIT() IsWithinLimit(GET_TEMPERATURE_IN_C(Temperature), &TempParamAttributes)

#define STATE_OF_CHARGE_MIN 20.0
#define STATE_OF_CHARGE_MAX 80.0
#define IS_STATE_OF_CHARGE_IN_LIMIT() IsWithinLimit(StateOfCharge, &SocParamAttributes)

#define CHARGE_RATE_MIN 0.1
#define CHARGE_RATE_MAX 0.8
#define IS_CHARGE_RATE_IN_LIMIT() IsWithinLimit(ChargeRate, &ChRateParamAttributes)

#define IN_LIMIT    1
#define NOT_IN_LIMIT    0

#define INLIMIT_TOLERANCE_PERCENTAGE  (float)(5/100)

extern const ParamAttributes TempParamAttributes;
extern const ParamAttributes SocParamAttributes;
extern const ParamAttributes ChRateParamAttributes;
extern const char * WarningMessage[];

extern float Temperature;
extern float StateOfCharge;
extern float ChargeRate;

extern int IsWithinLimit(float paramValue, const ParamAttributes * param);
extern int batteryIsOk(void);

extern ParamLevel getInLimitParamLevel(float paramValue, const ParamAttributes * param);
extern ParamLevel getOutLimitParamLevel(float paramValue, const ParamAttributes * param);
extern void ReportWarningMessage(ParamLevel level, const ParamAttributes * param);

extern float convertFarenheitToCelcius(float temp);

#endif
