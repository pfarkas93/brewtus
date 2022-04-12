#include "HTIM_Timer.h"

TESTABLE_STATIC volatile bool SV_isTimerTickArrived = false;

void HTIM_InitTimer(void)
{
}

bool HTIM_IsTimerTickArrived(void)
{
    bool isTimerTickArrived = false;
    if (false != SV_isTimerTickArrived)
    {
        isTimerTickArrived = true;
        SV_isTimerTickArrived = false;
    }
    else
    {
        SV_isTimerTickArrived = true;
    }
    return isTimerTickArrived;
}