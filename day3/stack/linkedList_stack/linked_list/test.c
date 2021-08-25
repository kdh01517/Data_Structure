///#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType
{
    int data;
    struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
    int currentElementCount;
    ListNode headerNode;
} LinkedList;

LinkedList* createLinked()
{
    LinkedList *list;

    list = malloc(sizeof(LinkedList));
    if (!list)
        return (0);
    list->headerNode.data = 0;
    list->currentElementCount = 0;
    list->headerNode.pLink = NULL;
    return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode *curNode = &pList->headerNode;
    ListNode *preNode = &pList->headerNode;

    if (pList->currentElementCount < position)
    {
        printf("over range\n");
        return (-1);
    }
    for (int i = 0; i < position -1; i++)
        preNode = preNode->pLink;
    for (int i = 0; i < position; i++)
        curNode = curNode->pLink;
    if (pList->currentElementCount == position)
    {
        element.pLink = NULL;
        curNode->pLink = &element; 
    }
    else if (pList->currentElementCount == position && p)
    {

    }
    else //1->2-> a->  3->4-> b-> NULL
    {
        element.pLink = curNode;
        preNode->pLink = &element; 
    }
    pList->currentElementCount++;
    return (pList->currentElementCount);
}

int removeLLEment(LinkedList* pList, int position)
{
    ListNode *curNode = &pList->headerNode;
    ListNode *preNode = &pList->headerNode;
    
    if (pList->currentElementCount < position)
    {
        printf("over range\n");
        return (-1);
    }
    for (int i = 0; i < position -1; i++)
        preNode = preNode->pLink;
    for (int i = 0; i < position; i++)
        curNode = curNode->pLink;
    preNode->pLink = curNode->pLink;
    free(curNode);
    curNode = NULL;
    pList->currentElementCount--;
    return (0);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode *curNode = &pList->headerNode;
    if (pList->currentElementCount < position)
    {
        printf("over range\n");
        return (-1);
    }
    for (int i = 0; i < position; i++)
        curNode = curNode->pLink;
    return (curNode);
}

void clearLinkedList(LinkedList* pList)
{
    LinkedList tmp;

    // 리스트 끝까지 노드 이동
    while (pList)
        pList->headerNode = pList->headerNode.pLink;
    // 노드가 있다면 현재 노드 free
    while (pList)
    {
        tmp = pList->headerNode;
        free(pList);
        pList = tmp;
    }
}

int getLinkedListLength(LinkedList* pList)
{
    // 리스트 처음으로 이동
    while (pList)
    {
        if (pList->headerNode)
            pList = pList->headerNode;
        else
            break;
    }
    // 리스트 끝까지 노드 이동
    while (pList)
        pList->headerNode = pList->headerNode.pLink;
    return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
    LinkedList tmp;

    tmp = 0;
    // 리스트 끝까지 노드 이동
    while (pList)
        pList->headerNode = pList->headerNode.pLink;
    tmp = pList->headerNode;
    tmp->headerNode.pLink = 0;
    free(pList);
    pList = tmp;
}

int main(void)
{
    LinkedList* list;
    list = createLinked();
    printf("%d\n", list->headerNode.data);
}