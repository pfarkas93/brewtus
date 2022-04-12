#include "unity.h"
#include "UnityHelper.h"
#include "RTIM_Timer.h"
#include "mock_HTIM_Timer.h"
#include "mock_TIM_OneShotCallbackHandler.h"

void setUp(void)
{
    mock_TIM_OneShotCallbackHandler_Init();
    mock_HTIM_Timer_Init();
}

void tearDown(void)
{
    mock_TIM_OneShotCallbackHandler_Verify();
    mock_HTIM_Timer_Verify();

    mock_TIM_OneShotCallbackHandler_Destroy();
    mock_HTIM_Timer_Destroy();
}

/*RTIM_InitTimer()************************************************************/
void test_GivenTimerPresent_WhenInitTimerIsCalled_ThenExpectCallHTIMInitTimer(void)
{
    HTIM_InitTimer_Expect();

    RTIM_InitTimer();
}

/*RTIM_UpdateTimerServices()************************************/
void test_GivenTimerTickNotArrived_WhenUpdateTimerServicesIsCalled_ThenExpectDoNothing(void)
{
    HTIM_IsTimerTickArrived_ExpectAndReturn(false);

    RTIM_UpdateTimerServices();
}

void test_GivenTimerTickArrived_WhenUpdateTimerServicesIsCalled_ThenExpectHandleTickArrived(void)
{
    HTIM_IsTimerTickArrived_ExpectAndReturn(true);
    TIM_OneShotCallbackHandler_DecrementRemainingTimeByOne_Expect();
    TIM_OneShotCallbackHandler_FireAndDeleteCallbackIfReady_Expect();

    RTIM_UpdateTimerServices();
}

/*RTIM_RegisterOneShotTimerAlarmCallback()***********************************/
void test_GivenTimerPresent_WhenRegisterOneShotTimerAlarmCallbackIsCalled_ThenExpectSetCallbackToTIMHandler(void)
{
    uint16_t testPeriod = 5u;
    TimerCallbackFunction_t testCallbackFunction;
    TIM_OneShotCallbackHandler_SetCallback_Expect(testCallbackFunction, testPeriod);

    RTIM_RegisterOneShotTimerAlarmCallback(testCallbackFunction, testPeriod);
}

/*IsOneShotTimerAlarmCallbackServiceAvailable()******************************/
void test_GivenCallbackSlotEmpty_WhenIsOneShotTimerAlarmCallbackServiceAvailableIsCalled_ThenExpectReturnTrue(void)
{
    bool isOneShotTimerAlarmCallbackServiceAvailable = false;

    TIM_OneShotCallbackHandler_IsCallbackSlotEmpty_ExpectAndReturn(true);
    isOneShotTimerAlarmCallbackServiceAvailable = RTIM_IsOneShotTimerAlarmCallbackServiceAvailable();
    TEST_ASSERT_TRUE(isOneShotTimerAlarmCallbackServiceAvailable);
}

void test_GivenCallbackSlotNotEmpty_WhenIsOneShotTimerAlarmCallbackServiceAvailableIsCalled_ThenExpectReturnFalse(void)
{
    bool isOneShotTimerAlarmCallbackServiceAvailable = false;

    TIM_OneShotCallbackHandler_IsCallbackSlotEmpty_ExpectAndReturn(false);
    isOneShotTimerAlarmCallbackServiceAvailable = RTIM_IsOneShotTimerAlarmCallbackServiceAvailable();
    TEST_ASSERT_FALSE(isOneShotTimerAlarmCallbackServiceAvailable);
}