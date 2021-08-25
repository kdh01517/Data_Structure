#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayListNodeType
{
    int data;
} ArrayListNode;

typedef struct ArrayListType
{
    int maxElementCount;
    int currentElementCount;
    ArrayListNode *pElement;
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList, int position, ArrayListNode element);
int removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);
ArrayListNode createNode(int data);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE
#define FALSE

#endif