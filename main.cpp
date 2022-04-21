#include "mbed.h"
#include "led1_class.h"
#include "led2_class.h"

//Instantiate Class objects
led1_class class_led1(PA_13, PC_10);
led2_class class_led2(PA_14);

int main()
{
    while (true) {

        class_led1.ButtonISR();
        class_led2.TickerISR();

        sleep();
    }
}