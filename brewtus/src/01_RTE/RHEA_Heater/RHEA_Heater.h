#ifndef _RHEA_HEATER_H_
#define _RHEA_HEATER_H_

#include "Types.h"
/**
 * @brief Init heater
 * @return none
 */
extern void RHEA_InitHeater(void);

/**
 * @brief Turn heater on
 * @return none
 */
extern void RHEA_TurnHeaterOn(void);

/**
 * @brief Turn heater off
 * @return none
 */
extern void RHEA_TurnHeaterOff(void);

/**
 * @brief Is heater off
 * @return True, if heater is off
 */
extern bool RHEA_IsHeaterOff(void);

/**
 * @brief Is heater on
 * @return True, if heater is on
 */
extern bool RHEA_IsHeaterOn(void);

#endif //_RHEA_HEATER_H_