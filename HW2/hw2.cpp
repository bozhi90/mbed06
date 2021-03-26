#include "mbed.h"
#include "mbed_events.h"
using namespace std::chrono;

EventQueue Queue1;
EventQueue Queue2;

void print_1() {
    while(1) {
        printf("1\n");
        ThisThread::sleep_for(500ms);
    }
}

void print_2() {
    while(1) {
        printf("2\n");
        ThisThread::sleep_for(500ms);
    }
}

int main() 
{
    Thread printf1Thread(osPriorityLow);
    printf1Thread.start(callback(&Queue1, &EventQueue::dispatch_forever));

    Thread printf2Thread(osPriorityNormal);
    printf2Thread.start(callback(&Queue2, &EventQueue::dispatch_forever));

    Queue1.call(print_1);
    Queue2.call(print_2);

    while (1) {
        ThisThread::sleep_for(1s);
        printf("33333\n\r");
    }
}