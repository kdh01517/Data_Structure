#include "Queue_simul.h"
#include <stdio.h>
int main(void)
{
    Deque dq;
    ListNode node;
    createDeque(&dq);
    int check_time = 0;
    SimCustomer customer[5];
    cus_init(&customer[0], 0, 3);
    cus_init(&customer[1], 2, 2);
    cus_init(&customer[2], 4, 1);
    cus_init(&customer[3], 6, 1);
    cus_init(&customer[4], 8, 3);
    for (int i = 0; i < 5; i++)
    {
        while (1)
        {
            int cnt = 0;
            while (cnt != customer[i].serviceTime || customer[i].status == arrival)
            {
                customer[i].status = start;
                if (check_time == customer[i].arrivalTime || IsEmpty(&dq))
                {
                    customer[i].startTime = check_time;
                    node.data = &customer[i];
                    pushBack(&dq, node);
                }
                if ((*(SimCustomer*)getFront(&dq)).arrivalTime > check_time)
                {
                    printf("대기상태 [customer%d]\n", i);
                    printf("도착시간 : %d, 현재시간 : %d, 서비스시간 : %d\n", (*(SimCustomer*)getFront(&dq)).arrivalTime, check_time, (*(SimCustomer*)getFront(&dq)).serviceTime);
                }
                cnt++;
                check_time++;
            }
            break;
        }
        customer[i].status = end;
        customer[i].endTime = customer[i].startTime + customer[i].serviceTime;
        printf("시물레이션 결과 [customer%d]\n", i);
        printf("도착시간 : %d, 시작시간 : %d, 서비스시간 : %d, 종료시간 : %d\n", (*(SimCustomer*)getFront(&dq)).arrivalTime/*customer[i].arrivalTime*/, (*(SimCustomer*)getFront(&dq)).startTime, (*(SimCustomer*)getFront(&dq)).serviceTime, (*(SimCustomer*)getFront(&dq)).endTime);
        popFront(&dq);
    }
}