#ifndef _QUEUE_SIMUL
#define _QUEUE_SIMUL
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Deque.h"

typedef enum SimStatusType {arrival, start, end} SimStatus;

typedef struct SimCustomerType
{
    SimStatus status;
    int arrivalTime; // 도착시간
    int serviceTime; // 서비스 시간
    int startTime; // 시작 시간;
    int endTime; // 종료 시각: 시작 시각 + 서비스 시간
} SimCustomer;

SimCustomer* cus_init(SimCustomer *customer, int arrive, int service);

#endif