#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include "stdio.h"
#include "stdlib.h"
typedef struct ListNodeType
{
    int data;
    struct ListNodeType* pLink;  //그다음 노드.
} ListNode;

typedef struct LinkedListType
{
    int currentElementCount; // 현재 저장된 원소의 개수
    ListNode headerNode; // 헤더 노드
} LinkedList;

ListNode *createNode(int data);
LinkedList* createLinked();
int addLLElement(LinkedList* pList, int position, ListNode *element);
int removeLLEment(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE
#define FALSE

#endif