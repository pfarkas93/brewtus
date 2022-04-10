#include "unity.h"
#include "UnityHelper.h"
#include "RHEA_Heater.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*RHEA_InitHeater*********************************************************************/
void test_GivenHeaterPresent_WhenInitHeaterIsCalled_ThenExpectNothing(void)
{
    RHEA_InitHeater();
}

/*RHEA_TurnHeaterOn*******************************************************************/
void test_GivenHeaterPresent_WhenTurnHeaterOnIsCalled_ThenExpectNothing(void)
{
    RHEA_TurnHeaterOn();
}

/*RHEA_TurnHeaterOff******************************************************************/
void test_GivenHeaterPresent_WhenTurnHeaterOffIsCalled_ThenExpectNothing(void)
{
    RHEA_TurnHeaterOff();
}

/*RHEA_IsHeaterOff******************************************************************/
void ignore_GivenHeaterOff_WhenIsHeaterOffIsCalled_ThenExpectReturnTrue(void)
{
    TEST_ASSERT_EQUAL(true, RHEA_IsHeaterOff());
}

void ignore_GivenHeaterOn_WhenIsHeaterOffIsCalled_ThenExpectReturnFalse(void)
{
    TEST_ASSERT_EQUAL(false, RHEA_IsHeaterOff());
}

/*RHEA_IsHeaterOn******************************************************************/

void ignore_GivenHeaterOn_WhenIsHeaterOnIsCalled_ThenExpectReturnTrue(void)
{
    TEST_ASSERT_EQUAL(true, RHEA_IsHeaterOn());
}

void ignore_GivenHeaterOff_WhenIsHeaterOnIsCalled_ThenExpectReturnFalse(void)
{
    TEST_ASSERT_EQUAL(false, RHEA_IsHeaterOn());
}