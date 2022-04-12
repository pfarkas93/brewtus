#ifndef _RTIM_TIMER_H_
#define _RTIM_TIMER_H_

#include "Types.h"
#include "TIM_TimerCallbackTypes.h"

/**
 * @brief Init Timer
 * @return none
 */
void RTIM_InitTimer(void);

/**
 * @brief Register one shot timer alarm callback.
 * The callback will be called, only once, when the given period is over.
 * @param[in] callback The callback function to be registered
 * @param[in] periodInSeconds The alarm period in seconds. The callback will be called after this time is elapsed.
 * @return none
 */
void RTIM_RegisterOneShotTimerAlarmCallback(TimerCallbackFunction_t callback, uint16_t periodInSeconds);

/**
 * @brief Update timer services
 * Check if Timer tick arrived, handle callback alarms.
 * @return none
 */
void RTIM_UpdateTimerServices(void);

/**
 * @brief Check if oneshot timer alarm callback service is available
 * @return true, if the oneshot timer alarm callback service is available
 */
bool RTIM_IsOneShotTimerAlarmCallbackServiceAvailable(void);

#endif //_RTIM_TIMER_H_