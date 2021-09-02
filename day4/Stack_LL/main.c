#include "Stack.h"

int main()
{
	Stack *stack = NULL;
	ListNode node;
	int maxElementCount = 6;

	stack = createStack(maxElementCount);

	// printf("Now, Stack is Full? : %d\n", IsFull(stack));

	// node.data_Char = 'A';
	// push(stack, node);

	// printf("[ peek index : %c ]\n", peek(stack));

	// node.data_Char = 'B';
	// push(stack, node);

	// printf("[ peek index : %c ]\n", peek(stack));

	// node.data_Char= 'C';
	// push(stack, node);

	// printf("[ peek index : %c ]\n", peek(stack));

	// node.data_Char = 'D';
	// push(stack, node);

	// node.data_Char = 'E';
	// push(stack, node);

	// node.data_Char = 'F';
	// push(stack, node);

	// printf("Now, Stack is Full? : %d\n", IsFull(stack));

	// node.data_Char = 'G';
	// push(stack, node);

	// printf("[ peek index : %c ]\n", peek(stack));

	// displayStackElement(stack);

	// pop(stack);

	// printf("[ peek index : %c ]\n", peek(stack));

	// displayStackElement(stack);

	//char* expression = "((A*B)/C)-{(D+E)&&(F-G)}";
	//char* expression = "((A*B)/C-{(D+E)&&(F-G))}";
	//char* expression = "{(A+B)*C}";
	//char* expression = "(())())";
	//char* expression = "(((()())()";
	//char* expression = "(()())((()))";
	char* expression = "((()()(()))(((())))()";
	//char* expression = "()()()()(()()())()";
	//char* expression = "(()((())()(";
	//char* expression = "((";
	//char* expression = "))";
	//char* expression = "())(()";

	printf("%d\n", checkBracketMatching(stack, expression));
	displayStackElement(stack);
}
