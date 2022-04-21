#include "mbed.h"

//InterruptIn button(PC_10);
//Ticker ticker;

//DigitalOut led1(PA_13);
//DigitalOut led2(PA_14);

//volatile int g_ISR_flag_1 = 0;
//volatile int g_ISR_flag_2 = 0;

//void isr1();
//void isr2();

//int state1 = 0;
//int state2 = 0;


class led1_class {
    public:
        int class_ISR_flag_1 = 0;

        led1_class(PinName inputPin, PinName interruptPin) {
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

        void ButtonISR() {
            if (class_ISR_flag_1) {Blink();}
        }

        void Blink() {
            class_ISR_flag_1 = 0;
            _state = !_state;
            _green_led_pin -> write(_state);
        }

        void class_isr1() {
            class_ISR_flag_1 = 1;
        }
    
    private:
        DigitalOut *_green_led_pin;
        InterruptIn *_button;
        int _state;
};

class led2_class {
    public:
        int class_ISR_flag_2 = 0;

        led2_class(PinName inputPin) {
            //Assign given Pin as DigitalOut
            _red_led_pin = new DigitalOut(inputPin);
            //Create new ticker
            _ticker = new Ticker();
            //Initialise led
            _red_led_pin -> write(0);
            _state = 0;
            //Initialise ticker
            _ticker -> attach(callback(this, &led2_class::class_isr2), 500ms);
        }

        void TickerISR() {
            if (class_ISR_flag_2) {Blink();}
        }

        void Blink() {
            class_ISR_flag_2 = 0;
            _state = !_state;
            _red_led_pin -> write(_state);
        }

        void class_isr2() {
            class_ISR_flag_2 = 1;
        }
    
    private:
        DigitalOut *_red_led_pin;
        Ticker *_ticker;
        int _state;
};

//Instantiate Class objects
led1_class class_led1(PA_13, PC_10);
led2_class class_led2(PA_14);

int main()
{
    //button.rise(&isr1);
    //button.rise(callback(&class_led1, &led1_class::class_isr1));
    //button.mode(PullNone);

    //ticker.attach(&isr2, 500ms);
    //ticker.attach(callback(&class_led2, &led2_class::class_isr2), 1s);

    //led1 = state1;
    //led2 = state2;

    while (true) {

        class_led1.ButtonISR();
        class_led2.TickerISR();

        sleep();

/*
        if (class_led1.class_ISR_flag_1) {
            class_led1.Blink();
        }
*/
/*
        if (class_led2.class_ISR_flag_2) {
            class_led2.Blink();
        }
*/
/*
        if (g_ISR_flag_1) {
            g_ISR_flag_1 = 0;
            led1 = state1 = !state1;
        }
*/
/*
        if (g_ISR_flag_2) {
            g_ISR_flag_2 = 0;
            led2 = state2 = !state2;
        }
*/
    }
}

/*
// This isr is replaced with one in the led1_class Class
void isr1() {
    g_ISR_flag_1 = 1;
}
*/

/* 
// This isr is replaced with one in the led2_class Class
void isr2() {
    g_ISR_flag_2 = 1;
}
*/