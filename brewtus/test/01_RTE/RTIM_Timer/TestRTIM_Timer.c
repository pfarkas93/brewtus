#include "unity.h"
#include "UnityHelper.h"
#include "RTIM_Timer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*RTIM_InitTimer()************************************************************/
void test_GivenTimerPresent_WhenInitTimerIsCalled_ThenExpectNothing(void)
{
    RTIM_InitTimer();
}

/*RTIM_RegisterOneShotTimerAlarmCallback()************************************/
void test_GivenAllSlotsEmpty_WhenRegisterOneShotTimerAlarmCallbackIsCalled_ThenExpect(void)
{
}

/*RTIM_RegisterPeriodicTimerAlarmCallback()***********************************/
/*RTIM_NotifySubscribers()****************************************************/
