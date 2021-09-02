#include "Stack.h"
#define X first
#define Y second
int board[8][8] =
{
    {0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0}
};
int vis[8][8];
int move[4][2] = 
{
    {1, 0}, // 아래으로이동.
    {0, 1}, // 오른쪽으로이동.
    {-1, 0}, // 위으로이동.
    {0, -1} // 왼쪽으로이동
};

int main(void)
{
    ArrayListArray *arList;
    ArrayList *aList;
    Stack *stack = NULL;
	ListNode node1; // row
    
    int maxElementCount = 8;
    stack = createStack(maxElementCount);
    aList = createArrayList(maxElementCount);
    arList = addAList(maxElementCount);

    node1.data = 0;
    addALLElement(aList, 0, node1);
    //node1.data_y = 0;
    push(stack, node1);
    printf("%d\n", stack.array->aList[0]->pElement[0].data);
    vis[0][0] = 1;
    while (!IsEmpty(stack))
    {
        int cur[1][2] = {0,};
        cur[0][0] = top(stack).element.data_x;// ->array->pElement->data_x;
        cur[0][1];
        stack->top++;
        pop(stack);
        printf("(%d, %d)->", cur[0][0], cur[0][1]);
        for(int dir = 0; dir < 4; dir ++){
            int nx = cur[0][0] + move[dir][0];
            int ny = cur[0][1] + move[0][dir]; 
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            if (vis[nx][ny] || board[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            push(stack, node1);
        }
    }
    printf("\n");
}