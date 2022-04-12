#include "unity.h"
#include "UnityHelper.h"
#include "TIM_OneShotCallbackHandler.h"

extern TimerCallback_t S_oneShotTimerCallback;
static TimerCallbackFunction_t testCallbackFunction;
static uint16_t testPeriodInSeconds;
static bool test_isCallbackCalled;

static void TestCallback(void);

void setUp(void)
{
    S_oneShotTimerCallback.callbackFunction = NULL;
    S_oneShotTimerCallback.periodInSeconds = 0u;
    S_oneShotTimerCallback.remainingTimeInSeconds = 0u;
    test_isCallbackCalled = false;
    testCallbackFunction = &TestCallback;
}

void tearDown(void)
{
}

/*TIM_OneShotCallbackHandler_SetCallback()***********************************/
void test_GivenEmptyCallbackSlot_WhenSetCallbackIsCalled_ThenExpectSettingCallback(void)
{
    testPeriodInSeconds = 5u;
    TIM_OneShotCallbackHandler_SetCallback(testCallbackFunction, testPeriodInSeconds);

    TEST_ASSERT_EQUAL(testCallbackFunction, S_oneShotTimerCallback.callbackFunction);
    TEST_ASSERT_EQUAL(testPeriodInSeconds, S_oneShotTimerCallback.periodInSeconds);
    TEST_ASSERT_EQUAL(testPeriodInSeconds, S_oneShotTimerCallback.remainingTimeInSeconds);
}

/*TIM_OneShotCallbackHandler_IsCallbackSlotEmpty()***************************/
void test_GivenEmptyCallbackSlot_WhenIsCallbackSlotEmptyIsCalled_ThenExpectReturnTrue(void)
{
    bool isSlotEmpty = TIM_OneShotCallbackHandler_IsCallbackSlotEmpty();

    TEST_ASSERT_TRUE(isSlotEmpty);
}

void test_GivenNotEmptyCallbackSlot_WhenIsCallbackSlotEmptyIsCalled_ThenExpectReturnFalse(void)
{
    bool isSlotEmpty = false;

    S_oneShotTimerCallback.callbackFunction = testCallbackFunction;

    isSlotEmpty = TIM_OneShotCallbackHandler_IsCallbackSlotEmpty();

    TEST_ASSERT_FALSE(isSlotEmpty);
}

/*TIM_OneShotCallbackHandler_DecrementRemainingTimeByOne()***************************/
void test_GivenRemainingTimeZero_WhenDecrementRemainingTimeByOneIsCalled_ThenExpectDoNothing(void)
{
    S_oneShotTimerCallback.remainingTimeInSeconds = 0u;
    TIM_OneShotCallbackHandler_DecrementRemainingTimeByOne();

    TEST_ASSERT_EQUAL(0u, S_oneShotTimerCallback.remainingTimeInSeconds);
}

void test_GivenRemainingTimeOne_WhenDecrementRemainingTimeByOneIsCalled_ThenExpectRemainingTimeBecomesZero(void)
{
    S_oneShotTimerCallback.remainingTimeInSeconds = 1u;
    TIM_OneShotCallbackHandler_DecrementRemainingTimeByOne();

    TEST_ASSERT_EQUAL(0u, S_oneShotTimerCallback.remainingTimeInSeconds);
}

void test_GivenRemainingTimeTwo_WhenDecrementRemainingTimeByOneIsCalled_ThenExpectRemainingTimeBecomesOne(void)
{
    S_oneShotTimerCallback.remainingTimeInSeconds = 2u;
    TIM_OneShotCallbackHandler_DecrementRemainingTimeByOne();

    TEST_ASSERT_EQUAL(1u, S_oneShotTimerCallback.remainingTimeInSeconds);
}

/*TIM_OneShotCallbackHandler_FireAndDeleteCallbackIfReady()***************************/
void test_GivenRemainingTimeNotZero_WhenFireAndDeleteCallbackIfReadyIsCalled_ThenExpectDoNothing(void)
{
    S_oneShotTimerCallback.callbackFunction = testCallbackFunction;
    S_oneShotTimerCallback.periodInSeconds = 5u;
    S_oneShotTimerCallback.remainingTimeInSeconds = 1u;
    TIM_OneShotCallbackHandler_FireAndDeleteCallbackIfReady();

    TEST_ASSERT_FALSE(test_isCallbackCalled);
}

void test_GivenRemainingTimeZero_WhenFireAndDeleteCallbackIfReadyIsCalled_ThenExpectCallAndDeleteCallback(void)
{
    S_oneShotTimerCallback.callbackFunction = testCallbackFunction;
    S_oneShotTimerCallback.periodInSeconds = 5u;
    S_oneShotTimerCallback.remainingTimeInSeconds = 0u;
    TIM_OneShotCallbackHandler_FireAndDeleteCallbackIfReady();

    TEST_ASSERT_TRUE(test_isCallbackCalled);
    TEST_ASSERT_EQUAL(NULL, S_oneShotTimerCallback.callbackFunction);
    TEST_ASSERT_EQUAL(0u, S_oneShotTimerCallback.periodInSeconds);
    TEST_ASSERT_EQUAL(0u, S_oneShotTimerCallback.remainingTimeInSeconds);
}

static void TestCallback(void)
{
    test_isCallbackCalled = true;
}