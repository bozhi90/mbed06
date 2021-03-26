#include "mbed.h"
using namespace std::chrono;

Ticker flipper;
DigitalOut led3(LED3);

void flip()
{
   led3 = !led3;
}

int main()
{
    led3 = 1;
    flipper.attach(&flip, 500ms);
    while(1);
}