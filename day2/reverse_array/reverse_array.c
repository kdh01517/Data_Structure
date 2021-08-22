#include "linkedlist.h"

//plink르 그전 노드의 주소로 변경하라.

void reverse_list(LinkedList *pList)
{
    ListNode *curNode = &pList->headerNode;
    ListNode *preNode = &pList->headerNode;
    ListNode *nodes = malloc(pList->currentElementCount * sizeof(ListNode));
    
    // for (int i = 0; i < pList->currentElementCount; i++)
    // {
    //     curNode->pLink = &nodes[i - 1];
    // }

    for (int i = 0; i < pList->currentElementCount; i++)
    {
        nodes[i] = *curNode->pLink;
        curNode = curNode->pLink;
    }
    for (int i = 0; i < pList->currentElementCount-1; i++)
    {
        if (i == 0)
        {
            nodes[i].pLink = NULL;
        }
        nodes[i+1].pLink = nodes[i].pLink;
    }
}

int main()
{
    LinkedList *list;
    /*
    createLinked(list);
    for (int i = 0; i < 10; i++) {
        addLLElement(list, i, createNode(i));
    }
    for (int i = 0; i < list->currentElementCount; i++){
        printf("%d " ,getLLElement(list, i)->data);
    }
    printf("\n");
    reverse_list(list);
    for (int i = 0; i < list->currentElementCount; i++){
        printf("%d " ,getLLElement(list, i)->data);
    }*/
    //// 이걸로 테스트 해보셔요
    for (int i = 0; i < 4; i++) {
        addLLElement(list, i, createNode(i));
    }
    for (int i = 1; i < list->currentElementCount + 1; i++){
        printf("%d " ,getLLElement(list, i)->data);
    }
    printf("\n");
    reverse_list(list);
    for (int i = list->currentElementCount; i > 0; i--){
        printf("%d " ,getLLElement(list, i)->data);
    }
}