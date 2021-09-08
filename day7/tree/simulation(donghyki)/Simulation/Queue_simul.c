#include "Queue_simul.h"

SimCustomer* cus_init(SimCustomer *customer, int arrive, int service)
{
    customer->arrivalTime = arrive;  // 도착시간
    customer->serviceTime = service; // 서비스 시간
    customer->startTime = 0;         // 시작 시간;
    customer->endTime = 0;           // 종료 시각: 시작 시각 + 서비스 시간
    customer->status = arrival;
    return (customer);
}

