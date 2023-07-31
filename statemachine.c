#include "statemachine.h"
#include "string.h"

void SM_LoopInfo_reset(SM_LoopInfo *loopInfo)
{
    loopInfo->stateTimeElapsedMs = 0;
}

void SM_StateMachine_init(SM_StateMachine *stateMachine, SM_HandlerFunctionPtr handlerFunctionPtr, int initialStateId,
                          SM_Transition *transitionList, int nTransitions)
{
    stateMachine->initialStateId = initialStateId;
    stateMachine->handlerFunctionPtr = handlerFunctionPtr;
    stateMachine->transitionList = transitionList;
    stateMachine->nTransitions = nTransitions;
    SM_StateMachine_reset(stateMachine);
}

void SM_StateMachine_reset(SM_StateMachine *stateMachine)
{
    stateMachine->currentStateId = stateMachine->initialStateId;
    SM_LoopInfo_reset(&stateMachine->loopInfo);
}

void SM_StateMachine_notifyEvent(SM_StateMachine *stateMachine, char *eventName)
{
    // find transition that matches src state id, event name
    SM_Transition* transition;
    int i;
    for(i=0; i<stateMachine->nTransitions; i++)
    {
        SM_Transition* iterTransition = &stateMachine->transitionList[i];
        if(iterTransition->srcId==stateMachine->currentStateId && strcmp(eventName, iterTransition->eventName)==0)
        {
            transition = iterTransition;
            break;
        }
    }

    // no transition found. return
    if(i == stateMachine->nTransitions)
        return;

    // update loopInfo
    stateMachine->loopInfo.stateTimeElapsedMs = 0;

    // transition to dst state
    stateMachine->currentStateId = transition->dstId;
}

void SM_StateMachine_spin(SM_StateMachine *stateMachine, int timeDeltaMs)
{
    stateMachine->loopInfo.stateTimeElapsedMs += timeDeltaMs;
    stateMachine->handlerFunctionPtr(stateMachine->currentStateId, &stateMachine->loopInfo);
}

