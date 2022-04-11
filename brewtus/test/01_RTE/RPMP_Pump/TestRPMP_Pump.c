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
