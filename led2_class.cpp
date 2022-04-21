#include "led2_class.h"

led2_class::led2_class(PinName inputPin) {
    //Assign given Pin as DigitalOut
    _red_led_pin = new DigitalOut(inputPin);
    //Assign given Pin as Ticker
    _ticker = new Ticker();
    //Initialise led
    _red_led_pin -> write(0);
    _state = 0;
    //Initialise ticker
    _ticker -> attach(callback(this, &led2_class::class_isr2), 500ms);
}

void led2_class::TickerISR() {
    if (class_ISR_flag_2) {Blink();}
}

void led2_class::Blink() {
    class_ISR_flag_2 = 0;
    _state = !_state;
    _red_led_pin -> write(_state);
}

void led2_class::class_isr2() {
    class_ISR_flag_2 = 1;
}