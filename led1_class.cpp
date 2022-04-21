#include "led1_class.h"

led1_class::led1_class(PinName inputPin, PinName interruptPin) {
    //Assign given Pin as DigitalOut
    _green_led_pin = new DigitalOut(inputPin);
    //Assign given Pin as InterruptIn
    _button = new InterruptIn(interruptPin);
    //Initialise led
    _green_led_pin -> write(0);
    _state = 0;
    //Initialise interrupt button
    _button -> rise(callback(this, &led1_class::class_isr1));
    _button -> mode(PullNone);
}

void led1_class::ButtonISR() {
    if (class_ISR_flag_1) {Blink();}
}

void led1_class::Blink() {
    class_ISR_flag_1 = 0;
    _state = !_state;
    _green_led_pin -> write(_state);
}

void led1_class::class_isr1() {
    class_ISR_flag_1 = 1;
}