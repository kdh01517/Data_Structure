#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
    int data;
}   ArrayListNode;

typedef struct ArrayListType
{
    int maxElementCount;
    int currentElementCount;
    ArrayList *pElement;
} ArrayList;

ArrayList* creatArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElememt(ArrayList* pList, int position, ArrayListNode element);
int removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE
#define FALSE

#endif