#include "mbed.h"

InterruptIn button(PC_10);
Ticker ticker;

DigitalOut led1(PA_13);
DigitalOut led2(PA_14);

volatile int g_ISR_flag_1 = 0;
volatile int g_ISR_flag_2 = 0;

void isr1();
void isr2();

int state1 = 0;
int state2 = 0;

int main()
{
    button.rise(&isr1);
    button.mode(PullNone);

    ticker.attach(&isr2, 500ms);

    led1 = state1;
    led2 = state2;

    while (true) {
        if (g_ISR_flag_1) {
            g_ISR_flag_1 = 0;
            led1 = state1 = !state1;
        }

        if (g_ISR_flag_2) {
            g_ISR_flag_2 = 0;
            led2 = state2 = !state2;
        }

        sleep();
    }
}

void isr1() {
    g_ISR_flag_1 = 1;
}

void isr2() {
    g_ISR_flag_2 = 1;
}


