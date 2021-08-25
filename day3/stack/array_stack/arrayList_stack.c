#include "arrayList_stack.h"

Stack *createArray_stack(int maxElementCount)
{
    Stack *stack = malloc(sizeof(stack));

    stack->list = createArrayList(maxElementCount);
    
    stack->maxElementCount = maxElementCount;
    stack->currentElementCount = 0;
    //stack->pElement = stack->list->pElement; 이렇게 하면 되안되냐...
    return (stack);
}

int push(Stack *stack, ArrayListNode data)
{

    if (stack->currentElementCount >= stack->maxElementCount)
    {
        printf("overflow\n");
        return (0);
    }
    else
    {
        addALElement(stack->list, stack->currentElementCount, data);
        stack->currentElementCount += 1;
    }
    
    return (1);
}

int pop(Stack *stack)
{
    int rData = getALElement(stack->list, stack->currentElementCount)->data;

    removeALElement(stack->list, stack->currentElementCount);
    stack->currentElementCount -= 1;
    stack->maxElementCount -= 1;
    return (rData);
}

int peek(Stack *stack)
{
    return (stack->pElement[stack->currentElementCount].data);
}

int main(void)
{
    Stack *stack;

    stack = createArray_stack(4);
    push(stack, createNode(1));
    push(stack, createNode(20));
    push(stack, createNode(111));
    addALElement(stack->list,1, createNode(500));

    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));

}