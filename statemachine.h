#include <stdio.h>
#include <stdbool.h>

#define SM_ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define SM_ANY_STATE -1

typedef struct SM_LoopInfo{
    unsigned int stateTimeElapsedMs;
}SM_LoopInfo;

typedef void (*SM_TransitionCallbackPtr)(int srcStateId, int dstStateId, const SM_LoopInfo* loopInfo);

typedef struct SM_Transition{
    char* eventName;
    int srcId;
    int dstId;
    SM_TransitionCallbackPtr callback;
}SM_Transition;

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

bool SM_StateMachine_notifyEvent(SM_StateMachine* stateMachine, char* eventName);

void SM_StateMachine_spin(SM_StateMachine* stateMachine, int timeDeltaMs);
