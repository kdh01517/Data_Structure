#ifndef _SINGLYLINKEDLIST_
#define _SINGLYLINKEDLIST_

typedef struct ListNodeType
{
	int data_Int;
	char data_Char;
	int data_x;
	int data_y;
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount; // 현재 저장된 원소의 개수
	ListNode headerNode; // 헤더 노드 (Header Node)
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
int isEmpty(LinkedList* pList);
void displayLinkedList(LinkedList* pList);

int reverseLinkedList(LinkedList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
