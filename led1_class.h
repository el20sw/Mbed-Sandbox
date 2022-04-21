#ifndef LED1_CLASS_H
#define LED1_CLASS_H

#include "mbed.h"

class led1_class {
    public:
        int class_ISR_flag_1 = 0;

        led1_class(PinName inputPin, PinName interruptPin);

        void ButtonISR();
        void Blink();
        void class_isr1();
    
    private:
        DigitalOut *_green_led_pin;
        InterruptIn *_button;
        int _state;
};

#endif