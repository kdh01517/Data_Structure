#include "linkedlist.h"

ListNode *createPolyNode(int x, int coef, int degree)
{
    ListNode *node;

    node = malloc(sizeof(ListNode));
    node->x = x;
    node->coef = coef;
    node->degree = degree;
    return (node);
}

int calculate_polynomial(LinkedList *plist)
{
    ListNode *polyNode;
    int sum = 0;
    int tmp = 1;

    for (int i = 1; i < plist->currentElementCount + 1; i++)
    {
        tmp = 1;
        polyNode = getLLElement(plist, i);
        for (int j = 0; j < polyNode->degree; j++)
            tmp *= polyNode->x; //차수  계산
        sum += polyNode->coef * tmp; // 계수  계산
    }
    return (sum);
}

int main()
{
    LinkedList *list;
    list = createLinked();
    //2^3
    addLLElement(list, 0, createPolyNode(2 ,2, 3)); //16
    addLLElement(list, 1, createPolyNode(3, 2, 3)); //54
    addLLElement(list, 2, createPolyNode(4, 2, 3)); //128
    printf("polynomial = %d\n", calculate_polynomial(list));
    clearLinkedList(list);

    
}