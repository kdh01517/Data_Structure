#include "ArrayList.h"
#include <stdio.h>

int main()
{
	int ArrayCount = 6;
	ArrayList *pList = NULL;
	ArrayListNode node;

	pList = createArrayList(ArrayCount);

	if (pList != NULL)
	{
		node.data_Int = 1;
		addALElement(pList, 0, node);

		printf("%d\n", node.data_Int);
		printf("%d\n", (pList->pElement[0]).data_Int);

		node.data_Int = 2;
		addALElement(pList, 1, node);
		printf("%d\n", (pList->pElement[1]).data_Int);

		node.data_Int = 3;
		addALElement(pList, 2, node);

		node.data_Int = 4;
		addALElement(pList, 3, node);

		displayArrayList(pList);
		removeALElement(pList, 1);
		displayArrayList(pList);

		clearArrayList(pList);
		displayArrayList(pList);

		ArrayListNode* pNode = NULL;
		pNode = getALElement(pList, 1);
		printf("%d\n", pNode->data_Int);
	}
}
