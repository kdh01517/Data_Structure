#include "Queue_simul.h"
#include <stdio.h>
int main(void)
{
    Deque dq;
    ListNode node;
    createDeque(&dq);
    Deque dq2;
    ListNode node2;
    createDeque(&dq2);
    int check_time = 0;
    SimCustomer customer[5];
    SimCustomer waiting[1];
    cus_init(&customer[0], 0, 3);
    cus_init(&customer[1], 2, 2);
    cus_init(&customer[2], 4, 1);
    cus_init(&customer[3], 6, 1);
    cus_init(&customer[4], 8, 3);
    cus_init(&waiting[0], 0, 0);
    for (int i = 0; i < 5; i++)
    {
        node.data = &customer[i];
        pushBack(&dq, node);
        printf("service = %d\n", customer[i].serviceTime);
    }

    while (1)
    {
        if (IsEmpty(&dq2) && !IsEmpty(&dq))
        {
            node2.data = popFront(&dq);
            pushBack(&dq2, node2);
            printf("waiting = %d\n", waiting[0].serviceTime);
            waiting[0].status = start;
        }
        int cnt = 0;
        while (cnt != waiting[0].serviceTime)
        {
            waiting[0].startTime = check_time;
            cnt++;
            check_time++;
        }
        waiting[0].status = end;
        waiting[0].endTime = waiting[0].startTime + waiting[0].serviceTime;
        printf("시물레이션 결과 [customer]\n");
        printf("도착시간 : %d, 시작시간 : %d, 서비스시간 : %d, 종료시간 : %d\n", waiting[0].arrivalTime, waiting[0].startTime, waiting[0].serviceTime, waiting[0].endTime);
        popFront(&dq2);
        if (IsEmpty(&dq2) && IsEmpty(&dq))
            break;
    }
}