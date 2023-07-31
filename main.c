#include <stdio.h>
#include "statemachine.h"

void stateMachineHandler(int currentStateId, const SM_LoopInfo* loopInfo)
{
    switch(currentStateId)
    {
        case 0:
        {
            printf(" %d (%d)\n", currentStateId, loopInfo->stateTimeElapsedMs);
            break;
        }
        case 1:
        {
            printf(" %d (%d)\n", currentStateId, loopInfo->stateTimeElapsedMs);
            break;
        }
        case 2:
        {
            printf(" %d (%d)\n", currentStateId, loopInfo->stateTimeElapsedMs);
            break;
        }
        default:
        {
            printf("undefined state\n");
        }
    }
}

int main()
{
    SM_Transition transitionList[] = {
            {"0to1", 0, 1},
            {"1to2", 1, 2},
            {"2to3", 2, 3},
    };
    SM_StateMachine stateMachine;
    SM_StateMachine_init(&stateMachine, &stateMachineHandler, 0, transitionList, 3);

    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_notifyEvent(&stateMachine, "0to1");
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_notifyEvent(&stateMachine, "1to2");
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_notifyEvent(&stateMachine, "2to3");
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    SM_StateMachine_spin(&stateMachine, 1);
    return 0;
}
