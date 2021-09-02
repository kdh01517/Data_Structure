#include "SinglyLinkedList.h"
#include <stdio.h>

int main()
{
	int ArrayCount = 0;
	LinkedList* pList = NULL;
	ListNode* pNode = NULL;
	ListNode node;

	pList = createLinkedList();

	if (pList != NULL)
	{
		node.data_Int = 1;
		addLLElement(pList, 0, node);

		node.data_Int = 2;
		addLLElement(pList, 1, node);

		node.data_Int = 5;
		addLLElement(pList, 2, node);

		node.data_Int = 10;
		addLLElement(pList, 3, node);

		node.data_Int = 13;
		addLLElement(pList, 4, node);

		node.data_Int = 15;
		addLLElement(pList, 5, node);

		displayLinkedList(pList);

		removeLLElement(pList, 0);

		displayLinkedList(pList);

		reverseLinkedList(pList);

		displayLinkedList(pList);
	}
}
