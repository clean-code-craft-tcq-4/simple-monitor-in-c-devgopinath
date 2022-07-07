
#ifndef CHECKER_H
#define CHECKER_H

#define TEMPERATURE_MIN 0.0
#define TEMPERATURE_MAX 45.0
#define IS_TEMPERATURE_IN_LIMIT() IsWithinLimit(Temperature, TEMPERATURE_MIN, TEMPERATURE_MAX, "Temperature")

#define STATE_OF_CHARGE_MIN 20.0
#define STATE_OF_CHARGE_MAX 80.0
#define IS_STATE_OF_CHARGE_IN_LIMIT() IsWithinLimit(StateOfCharge, STATE_OF_CHARGE_MIN, STATE_OF_CHARGE_MAX, "Start of Charge")

#define CHARGE_RATE_MIN 0.1
#define CHARGE_RATE_MAX 0.8
#define IS_CHARGE_RATE_IN_LIMIT() IsWithinLimit(ChargeRate, CHARGE_RATE_MIN, CHARGE_RATE_MAX, "Charge Rate")

#define IN_LIMIT    1
#define NOT_IN_LIMIT    0

extern float Temperature;
extern float StateOfCharge;
extern float ChargeRate;

extern int IsWithinLimit(float paramValue, float min, float max);
extern int batteryIsOk(void);

#endif
