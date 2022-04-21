#ifndef LED2_CLASS_H
#define LED2_CLASS_H

#include "mbed.h"

class led2_class {
    public:
        int class_ISR_flag_2 = 0;

        led2_class(PinName inputPin);

        void TickerISR();
        void Blink();
        void class_isr2();
    
    private:
        DigitalOut *_red_led_pin;
        Ticker *_ticker;
        int _state;
};

#endif