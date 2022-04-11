#include "unity.h"
#include "UnityHelper.h"
#include "RPMP_Pump.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*RPMP_InitPump*********************************************************************/
void test_GivenPumpPresent_WhenInitPumpIsCalled_ThenExpectNothing(void)
{
    RPMP_InitPump();
}

/*RPMP_TurnPumpOn*******************************************************************/
void test_GivenPumpPresent_WhenTurnPumpOnIsCalled_ThenExpectNothing(void)
{
    RPMP_TurnPumpOn();
}

/*RPMP_TurnPumpOff******************************************************************/
void test_GivenPumpPresent_WhenTurnPumpOffIsCalled_ThenExpectNothing(void)
{
    RPMP_TurnPumpOff();
}

/*RPMP_IsPumpOff******************************************************************/
void ignore_GivenPumpOff_WhenIsPumpOffIsCalled_ThenExpectReturnTrue(void)
{
    TEST_ASSERT_EQUAL(true, RPMP_IsPumpOff());
}

void ignore_GivenPumpOn_WhenIsPumpOffIsCalled_ThenExpectReturnFalse(void)
{
    TEST_ASSERT_EQUAL(false, RPMP_IsPumpOff());
}

/*RPMP_IsPumpOn******************************************************************/

void ignore_GivenPumpOn_WhenIsPumpOnIsCalled_ThenExpectReturnTrue(void)
{
    TEST_ASSERT_EQUAL(true, RPMP_IsPumpOn());
}

void ignore_GivenPumpOff_WhenIsPumpOnIsCalled_ThenExpectReturnFalse(void)
{
    TEST_ASSERT_EQUAL(false, RPMP_IsPumpOn());
}