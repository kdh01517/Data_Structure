#include "linkedList_stack.h"

Stack *createLinked_stack()
{
    Stack *stack = malloc(sizeof(stack));
    stack->list = createLinked();
    stack->currentElementCount = 0;
    stack->pTopElement.pLink = NULL;
    return(stack);
}

int push(Stack *stack, ListNode *data)
{
    // Stack *node = &stack->pTopElement;
    // if (!node)
    // {
    //     printf("Error!");
    //     return (0);
    // }
    // if (node->pTopElement.pLink == NULL)
    //     node->pTopElement.pLink = data;
    
    if(addLLElement(stack->list, stack->currentElementCount, data) == -1)
        return(-1);
    else
    {
        stack->currentElementCount++;
        return(1);
    }
}

int pop(Stack *stack)
{
    //peek();
    int rData = getLLElement(stack->list, stack->currentElementCount - 1)->data;
    removeLLEment(stack->list, stack->currentElementCount);
    stack->currentElementCount--;
    return (rData);
}

int peek(Stack *stack)
{
    return(getLLElement(stack->list, stack->currentElementCount - 1)->data);
}

int main()
{
    //스택 생성
    Stack *stack;
    
    stack = createLinked_stack();
    push(stack, createNode(1));
    push(stack, createNode(20));
    push(stack, createNode(111));
    for(int i = 0; i < stack->currentElementCount; i++){
        printf("%d\n", getLLElement(stack->list, i)->data);
    }
    printf("count %d\n", stack->currentElementCount);
    printf("%d\n", pop(stack));
    printf("count %d\n", stack->currentElementCount);
    printf("%d\n", peek(stack));
    printf("%d\n", pop(stack));
    printf("count %d\n", stack->currentElementCount);
    printf("%d\n", pop(stack));
    printf("count %d\n", stack->currentElementCount);
}