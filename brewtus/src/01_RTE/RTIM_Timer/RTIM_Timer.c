#include "RTIM_Timer.h"
#include "TIM_OneShotCallbackHandler.h"

/************************************/
/*Local variables*******************/
/**********************************/

/************************************/
/*Local function definitions********/
/**********************************/

/**
 * @brief Handle that if one second is elapsed.
 * Update Alarm service remaining times
 * Clear
 */
static void HandleOneSecondElapsed(void);

/************************************/
/*Global functions******************/
/**********************************/

void RTIM_InitTimer(void)
{
    /*HAL not present yet*/
}

void RTIM_UpdateTimerServices(void)
{
    // if()
    HandleOneSecondElapsed();
}

void RTIM_RegisterOneShotTimerAlarmCallback(TimerCallbackFunction_t *callback, uint16_t periodInSeconds)
{
    TIM_OneShotCallbackHandler_SetCallback(callback, periodInSeconds);
}

bool RTIM_IsOneShotTimerAlarmCallbackServiceAvailable(void)
{
    bool isOneShotCallbackSlotEmpty = TIM_OneShotCallbackHandler_IsCallbackSlotEmpty();
    return isOneShotCallbackSlotEmpty;
}

/************************************/
/*Local functions*******************/
/**********************************/

static void HandleOneSecondElapsed(void)
{
}
