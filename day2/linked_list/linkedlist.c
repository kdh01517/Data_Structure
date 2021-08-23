#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"

LinkedList* createLinked()
{
    LinkedList *list;

    list = malloc(sizeof(LinkedList));
    if (!list)
        return (0);
    list->currentElementCount = 0;
    list->headerNode.pLink = NULL;
    return (list);
}

ListNode *createNode(int data)
{
    ListNode *node;

    node = malloc(sizeof(ListNode));
    node->data = data;
    return (node);
}

int addLLElement(LinkedList* pList, int position, ListNode *element)
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
        element->pLink = NULL;
        curNode->pLink = element; 
    }
    else
    {
        element->pLink = curNode;
        preNode->pLink = element; 
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
    return (0);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode *curNode = pList->headerNode.pLink;
    if (pList->currentElementCount < position)
    {
        printf("over range\n");
        return (NULL);
    }
    for (int i = 0; i < position; i++)
        curNode = curNode->pLink;
    return (curNode);
}

void clearLinkedList(LinkedList* pList)
{
    ListNode *curNode = pList->headerNode.pLink;
    ListNode *tmpNode = pList->headerNode.pLink;

    for (int i = 0; i < pList->currentElementCount; i++)
    {
        tmpNode = curNode->pLink;
        free(curNode);
        curNode = NULL;
        curNode = tmpNode;
    }
    pList->currentElementCount = 0;
    free(pList);
}
int getLinkedListLength(LinkedList* pList)
{
    return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
    ListNode *curNode = &pList->headerNode;
    for (int i = 0; i < pList->currentElementCount -1; i++)
    {
        curNode = curNode->pLink;
    }
    free(curNode);
    curNode = NULL;
    pList->currentElementCount--;
}

int main(){
    LinkedList *list;

    list = createLinked();
    addLLElement(list, 0, createNode(1));
    addLLElement(list, 1, createNode(2));
    addLLElement(list, 2, createNode(3));
    addLLElement(list, 3, createNode(4));

    for (int i = 0; i < 10; i++) {
        addLLElement(list, i, createNode(i));
    }
    for (int i = 1; i < list->currentElementCount + 1; i++){
        printf("%d " ,getLLElement(list, i)->data);
    }
    clearLinkedList(list);
}