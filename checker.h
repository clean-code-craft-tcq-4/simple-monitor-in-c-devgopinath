
#ifndef CHECKER_H
#define CHECKER_H

typedef struct
{
    char * paramName;
    float max;
    float min;
    
} ParamAttributes;

#define TEMPERATURE_MIN 0.0
#define TEMPERATURE_MAX 45.0
#define IS_TEMPERATURE_IN_LIMIT() IsWithinLimit(Temperature, &TempParamAttributes)

#define STATE_OF_CHARGE_MIN 20.0
#define STATE_OF_CHARGE_MAX 80.0
#define IS_STATE_OF_CHARGE_IN_LIMIT() IsWithinLimit(StateOfCharge, &SocParamAttributes)

#define CHARGE_RATE_MIN 0.1
#define CHARGE_RATE_MAX 0.8
#define IS_CHARGE_RATE_IN_LIMIT() IsWithinLimit(ChargeRate, &ChRateParamAttributes)

#define IN_LIMIT    1
#define NOT_IN_LIMIT    0

extern const ParamAttributes TempParamAttributes;
extern const ParamAttributes SocParamAttributes;
extern const ParamAttributes ChRateParamAttributes;

extern float Temperature;
extern float StateOfCharge;
extern float ChargeRate;

extern int IsWithinLimit(float paramValue, float min, float max, char * paramName);
extern int batteryIsOk(void);

#endif
