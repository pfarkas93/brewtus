#include "TIM_OneShotCallbackHandler.h"

/************************************/
/*Local variables*******************/
/**********************************/
/**
 * @brief Static struct instance of the callback
 *
 */
TESTABLE_STATIC TimerCallback_t S_oneShotTimerCallback = {NULL, 0u, 0u};

/************************************/
/*Local function definitions********/
/**********************************/
/**
 * @brief Delete current callback
 * @return none
 */
static void OneShotCallbackHandler_DeleteCurrentCallback(void);

/************************************/
/*Global functions******************/
/**********************************/
void TIM_OneShotCallbackHandler_SetCallback(TimerCallbackFunction_t callbackFunction, uint16_t periodInSeconds)
{
    S_oneShotTimerCallback.callbackFunction = callbackFunction;
    S_oneShotTimerCallback.periodInSeconds = periodInSeconds;
    S_oneShotTimerCallback.remainingTimeInSeconds = periodInSeconds;
}

bool TIM_OneShotCallbackHandler_IsCallbackSlotEmpty(void)
{
    bool isCallbackSlotEmpty = (NULL == S_oneShotTimerCallback.callbackFunction);

    return isCallbackSlotEmpty;
}

void TIM_OneShotCallbackHandler_DecrementRemainingTimeByOne(void)
{
    if (0u < S_oneShotTimerCallback.remainingTimeInSeconds)
    {
        S_oneShotTimerCallback.remainingTimeInSeconds--;
    }
}

void TIM_OneShotCallbackHandler_FireAndDeleteCallbackIfReady(void)
{
    if (0u == S_oneShotTimerCallback.remainingTimeInSeconds)
    {
        S_oneShotTimerCallback.callbackFunction();
        OneShotCallbackHandler_DeleteCurrentCallback();
    }
}

/************************************/
/*Local functions*******************/
/**********************************/

static void OneShotCallbackHandler_DeleteCurrentCallback(void)
{
    S_oneShotTimerCallback.callbackFunction = NULL;
    S_oneShotTimerCallback.periodInSeconds = 0u;
    S_oneShotTimerCallback.remainingTimeInSeconds = 0u;
}