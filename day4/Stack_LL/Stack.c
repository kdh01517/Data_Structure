#include "Stack.h"

Stack* createStack(int maxElementCount)
{
	Stack *sp = malloc(sizeof(Stack));
	LinkedList* pList = NULL;
	pList = createLinkedList();
	sp->array = pList;
	sp->maxElementCount = maxElementCount;
	sp->top = pList->currentElementCount - 1;
	return (sp);
}

int IsEmpty(Stack* sp)
{
	if (sp->top == -1)
		return (TRUE);
	return (FALSE);
}

int StackLength(Stack *sp)
{
	return (sp->top + 1);
}

int IsFull(Stack *sp)
{
	if (StackLength(sp) >= sp->maxElementCount)
		return (TRUE);
	return (FALSE);
}

void push(Stack *sp, ListNode element)
{
	if (IsFull(sp))
		printf("You Can't push the elment. Now, Stack is Full\n");
	else
		addLLElement(sp->array, (++(sp->top)), element);
}

int pop(Stack *sp)
{
	if (IsEmpty(sp))
		return (ERROR);
	return (removeLLElement(sp->array, (sp->top)--));
}

char peek(Stack *sp)
{
	if (IsEmpty(sp))
	{
		printf("Stack is Empty. You can't access the peek of Stack\n");
		return (0);
	}
	return (getLLElement(sp->array, sp->top)->data_Char);
}

void displayStackElement(Stack *sp)
{
	printf("---------------------\n");
	for (int i = 0; i < sp->array->currentElementCount; i++)
		printf("[ %d 번째 인덱스 ] : %c\n", i, getLLElement(sp->array, i)->data_Char);
}

int checkBracketMatching(Stack *sp, char* expression)
{
	int result = TRUE;
	int i = 0;
	int count = 0;
	ListNode symbol;
	while (expression[i] != '\0' && result != FALSE)
	{
		symbol.data_Char = expression[i];
		switch(symbol.data_Char)
		{
			case '(': case '[': case '{':
				printf("%c is pushed stack\n", symbol.data_Char);
				push(sp, symbol);
				break;
			case ')':
				if (IsEmpty(sp))
					result = FALSE;
				else
				{
					ListNode checkSymbol;
					checkSymbol.data_Char = getLLElement(sp->array, sp->top)->data_Char;
					if (checkSymbol.data_Char != '(')
						result = FALSE;
					else
					{
						printf("%c is poped stack\n", checkSymbol.data_Char);
						pop(sp);
					}
				}
				break;
			case ']':
				if (IsEmpty(sp))
					result = FALSE;
				else
				{
					ListNode checkSymbol;
					checkSymbol.data_Char = getLLElement(sp->array, sp->top)->data_Char;
					if (checkSymbol.data_Char != '[')
						result = FALSE;
					else
					{
						printf("%c is poped stack\n", checkSymbol.data_Char);
						pop(sp);
					}
				}
				break;
			case '}':
				if (IsEmpty(sp))
					result = FALSE;
				else
				{
					ListNode checkSymbol;
					checkSymbol.data_Char = getLLElement(sp->array, sp->top)->data_Char;
					if (checkSymbol.data_Char != '{')
						result = FALSE;
					else
					{
						printf("%c is poped stack\n", checkSymbol.data_Char);
						pop(sp);
					}
				}
				break;
		}
		i++;
	}
	if (!IsEmpty(sp))
		result = FALSE;
	return (result);
}
