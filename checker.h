
#ifdef CHECKER_H
#define CHECKER_H

#define TEMPERATURE_MIN 0.0
#define TEMPERATURE_MAX 45.0
#define IS_TEMPERATURE_IN_LIMIT(currentValue) IsWithinLimit(currentValue, TEMPERATURE_MIN, TEMPERATURE_MAX)

#define STATE_OF_CHARGE_MIN 20.0
#define STATE_OF_CHARGE_MAX 80.0
#define IS_STATE_OF_CHARGE_IN_LIMIT(currentValue) IsWithinLimit(currentValue, STATE_OF_CHARGE_MIN, STATE_OF_CHARGE_MAX)

#define CHARGE_RATE_MIN 0.1
#define CHARGE_RATE_MAX 0.8
#define IS_CHARGE_RATE_IN_LIMIT(currentValue) IsWithinLimit(currentValue, CHARGE_RATE_MIN, CHARGE_RATE_MAX)

extern float Temperature;
extern float StateOfCharge;
extern float ChargeRate;

extern bool IsWithinLimit(float currentValue, float min, float max);
extern int batteryIsOk(void);

#endif
