#include "linkedlist.h"

void reverse_list(LinkedList *pList)
{
    ListNode *curNode = &pList->headerNode;
    ListNode *preNode = &pList->headerNode;
    ListNode *nodes = malloc(pList->currentElementCount * sizeof(ListNode));

    for (int i = 0; i < pList->currentElementCount; i++)
    {
        nodes[i] = *curNode->pLink;
        curNode = curNode->pLink;
    }
    for (int i = 0; i < pList->currentElementCount - 1; i++)
    {
        if (i == 0)
            nodes[i].pLink = NULL;
        nodes[i+1].pLink = nodes[i].pLink;
    }
    free(nodes);
}

int main()
{
    LinkedList *list;
    list = createLinked();

    for (int i = 0; i < 10; i++) {
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
    clearLinkedList(list);

}