#ifndef _TIM_ONESHOTCALLBACKHANDLER_H_
#define _TIM_ONESHOTCALLBACKHANDLER_H_

#include "Types.h"
#include "TIM_TimerCallbackTypes.h"

/**
 * @brief Set one shot callback
 * @param[in] callbackFunction The function pointer to the callback function to be registered
 * @param[in] periodInSeconds The alarm period in seconds. The callback will be called after this time is elapsed.
 * @return none
 */
void TIM_OneShotCallbackHandler_SetCallback(TimerCallbackFunction_t callbackFunction, uint16_t periodInSeconds);

/**
 * @brief Check if the oneshot callback slot is empty
 * @return true, if the callback slot is empty
 */
bool TIM_OneShotCallbackHandler_IsCallbackSlotEmpty(void);

/**
 * @brief Decrement the remaining time of the registered callback by one.
 * @return none
 */
void TIM_OneShotCallbackHandler_DecrementRemainingTimeByOne(void);

/**
 * @brief Fire the callback if the period is over. Delete the callback after fireing.
 * @return none
 */
void TIM_OneShotCallbackHandler_FireAndDeleteCallbackIfReady(void);

#endif //_TIM_ONESHOTCALLBACKHANDLER_H_
