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