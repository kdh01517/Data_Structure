#ifndef _ARRAYLIST_STACK_
#define _ARRAYLIST_STACK_

#include "arrayList/array_list.h"

typedef struct AaayListStack
{
    int maxElementCount;
    int currentElementCount;
    ArrayList *list;
    ArrayListNode *pElement;
} Stack;

int push(Stack *stack, ArrayListNode data);

int pop(Stack *stack);

int peek(Stack *stack);

#endif