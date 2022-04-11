#ifndef RPMP_PUMP_H
#define RPMP_PUMP_H

#include "Types.h"

/**
 * @brief Init Pump
 * @return none
 */
extern void RPMP_InitPump(void);

/**
 * @brief Turn Pump on
 * @return none
 */
extern void RPMP_TurnPumpOn(void);

/**
 * @brief Turn Pump off
 * @return none
 */
extern void RPMP_TurnPumpOff(void);

/**
 * @brief Is Pump off
 * @return True, if Pump is off
 */
extern bool RPMP_IsPumpOff(void);

/**
 * @brief Is Pump on
 * @return True, if Pump is on
 */
extern bool RPMP_IsPumpOn(void);
#endif