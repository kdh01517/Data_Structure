#ifndef _LINKEDLIST_STACK_
#define _LINKEDLIST_STACK_

#include "linked_list/linkedlist.h"

typedef struct LinkedListStack
{
    int currentElementCount;
    LinkedList *list;
    ListNode pTopElement;
} Stack;

int push(Stack *stack, ListNode *data);

int pop(Stack *stack);

int peek(Stack *stack);

#endif