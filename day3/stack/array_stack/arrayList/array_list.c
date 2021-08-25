#include "array_list.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList* array = malloc(sizeof(ArrayList));

    array->pElement = malloc(sizeof(ArrayListNode)*maxElementCount);
    if (!array)
        return (0);
    array->maxElementCount = maxElementCount;
    array->currentElementCount = 0;
    return (array);
}

ArrayListNode createNode(int data)
{
    ArrayListNode node;

    node.data = data;
    return (node);
}

void deleteArrayList(ArrayList* pList)
{

    free(pList->pElement);
    pList->currentElementCount = 0;
    pList->maxElementCount = 0;
    pList->pElement = 0;
    free(pList);
}

int isArrayListFull(ArrayList* pList)
{
    if (pList->currentElementCount  >= pList->maxElementCount)
        return (1);
    return (0);
}
int addALElement(ArrayList* pList, int position, ArrayListNode element)
{    
    if (pList->maxElementCount < position 
        && pList->maxElementCount < pList->currentElementCount + 1)
    {
        printf("over range\n");
        return (-1);
    }
    for (int i = pList->currentElementCount - 1; i > position - 1; i--)
        pList->pElement[i + 1] = pList->pElement[i];
    pList->pElement[position] = element;
    pList->currentElementCount += 1;
    return (1);
}

int removeALElement(ArrayList* pList, int position)
{
    if (pList->maxElementCount < position || pList->currentElementCount -1 < 0)
    {
        printf("less range\n");
        return (-1);
    }
    for (int i = position + 1; i < pList->currentElementCount; i++)
        pList->pElement[i - 1] = pList->pElement[i];
    pList->currentElementCount -= 1;
    return (1);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    return (&(pList->pElement)[position]); 
    /*
        pList->pElement + position
        pList->pElements[position]; 는 안되는지...
        &(pList->pElement)[position];
    */
}

void displayArrayList(ArrayList* pList)
{
    printf("[");
    for (int i = 0; i < pList->currentElementCount; i++)
    {
        printf("%d ", pList->pElement[i].data);
    }
    printf("]\n");
}

int getArrayListLength(ArrayList* pList)
{
    return (pList->maxElementCount);
}

/* 
int main(void)
{
    ArrayList* array;
    array = createArrayList(4);
    printf("%d", array->currentElementCount);
    // for (int i  =0; i < 4; i++)
    //     addALElement(array, i, createNode(i));

    // addALElement(array, 2, createNode(100));
    // removeALElement(array, 0);
    // removeALElement(array, 3);
    // displayArrayList(array);
    // printf("%d\n", getArrayListLength(array));
    // printf("%d", getALElement(array, 2)->data);
} */