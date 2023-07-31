#include <stdio.h>
#include "statemachine.h"

enum StateID{
    STATE_ID_0,
    STATE_ID_1,
    STATE_ID_2,
};
void stateMachineHandler(int currentStateId, const SM_LoopInfo* loopInfo)
{
    switch(currentStateId)
    {
        case STATE_ID_0:
        {
            printf("State ID:%d (%d ms)\n", currentStateId, loopInfo->stateTimeElapsedMs);
            break;
        }
        case STATE_ID_1:
        {
            printf("State ID:%d (%d ms)\n", currentStateId, loopInfo->stateTimeElapsedMs);
            break;
        }
        case STATE_ID_2:
        {
            printf("State ID:%d (%d ms)\n", currentStateId, loopInfo->stateTimeElapsedMs);
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
            {"0to1", STATE_ID_0, STATE_ID_1},
            {"1to2", STATE_ID_1, STATE_ID_2},
    };
    SM_StateMachine stateMachine;
    SM_StateMachine_init(&stateMachine, &stateMachineHandler, 0, transitionList, SM_ARRAY_LEN(transitionList));

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
