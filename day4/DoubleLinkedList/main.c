#include "DoublyLinkedList.h"
#include <stdio.h>

int main()
{
	LinkedList* pList = NULL;
	ListNode node;

	pList = createLinkedList();

	if (pList != NULL)
	{
		node.data = 1;
		addLLElement(pList, 0, node);

		node.data = 2;
		addLLElement(pList, 1, node);

		node.data = 3;
		addLLElement(pList, 2, node);

		displayLinkedList(pList);

		removeLLElement(pList, 1);

		displayLinkedList(pList);
	}
	return 0;
}
