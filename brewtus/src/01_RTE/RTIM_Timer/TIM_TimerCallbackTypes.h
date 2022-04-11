#ifndef _TIM_TIMERCALLBACKTYPES_H_
#define _TIM_TIMERCALLBACKTYPES_H_

#include "Types.h"
/**
 * @brief Function pointer type for timer callbacks
 *
 */
typedef void (*TimerCallbackFunction_t)(void);

/** @struct TimerCallback
 *  @brief This structure contains a timer callback function and its period.
 *  @var TimerCallback::callbackFunction
 *  Member 'callbackFunction' is a pointer to the callback function that shall be called after the period is over.
 *  @var TimerCallback::periodInSeconds
 *  Member 'periodInSeconds' is the time in seconds, that shall be elapsed before the callback is called.
 *  @var TimerCallback::remainingTimeInSeconds
 *  Member 'remainingTimeInSeconds' is the remainig time from the period until the callback is called.
 */
typedef struct TimerCallback
{
    TimerCallbackFunction_t *callbackFunction;
    uint16_t periodInSeconds;
    uint16_t remainingTimeInSeconds;
} TimerCallback_t;

#endif //_TIM_TIMERCALLBACKTYPES_H_
