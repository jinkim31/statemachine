#include <stdio.h>

typedef struct SM_Transition{
    char* eventName;
    int srcId;
    int dstId;
}SM_Transition;

typedef struct SM_LoopInfo{
    unsigned int stateTimeElapsedMs;
}SM_LoopInfo;

void SM_LoopInfo_reset(SM_LoopInfo* loopInfo);

typedef void (*SM_HandlerFunctionPtr)(int currentStateId, const SM_LoopInfo* loopInfo);

typedef struct SM_StateMachine{
    SM_HandlerFunctionPtr handlerFunctionPtr;
    SM_Transition* transitionList;
    int nTransitions;
    SM_LoopInfo loopInfo;
    int initialStateId;
    int currentStateId;
}SM_StateMachine;

void SM_StateMachine_init(
        SM_StateMachine *stateMachine,
        SM_HandlerFunctionPtr handlerFunctionPtr, int initialStateId,
        SM_Transition *transitionList, int nTransitions);

void SM_StateMachine_reset(SM_StateMachine* stateMachine);

void SM_StateMachine_notifyEvent(SM_StateMachine* stateMachine, char* eventName);

void SM_StateMachine_spin(SM_StateMachine* stateMachine, int timeDeltaMs);