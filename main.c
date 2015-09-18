/* 
 * File:   main.c
 * Author: Justine Saugen
 * Description: lab 0.
 * Created on September 14, 2015, 2:34 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

//TODO: Define states of the state machine

typedef enum stateTypeEnum {
    led1, led2, led3, wait, wait2, debouncePress, debounceRelease, directionChange
} stateType;
volatile stateType state;
//TODO: Use volatile variables that change within interrupts

int main() {

    //This function is necessary to use interrupts. 
    enableInterrupts();

    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    initTimer2();
    initTimer1();
    int next = 1;
    int current = 1;
    state = wait;

    while (1) {
        switch (state) {
            case wait:
                if (PORTDbits.RD6 == 0) {
                    state = debouncePress;
                    T1CONbits.TON = 1;
                }
                break;

            case led1:
                current = 1;
                turnOnLED(current);
                next = 2;
                if (PORTDbits.RD6 == 0) {
                    state = debouncePress;
                    T1CONbits.TON = 1;
                }
                break;

            case led2:
                current = 2;
                turnOnLED(current);
                next = 3;
                if (PORTDbits.RD6 == 0) {
                    state = debouncePress;
                    T1CONbits.TON = 1;
                }
                break;

            case led3:
                current = 3;
                turnOnLED(current);
                next = 1;
                if (PORTDbits.RD6 == 0) {
                    state = debouncePress;
                    T1CONbits.TON = 1;
                }
                break;

            case debouncePress:
                if(PORTDbits.RD6 == 0 && IFS0bits.T1IF == 1) state = directionChange;
                if (PORTDbits.RD6 == 1 && next == 1) {
                    T1CONbits.TON = 0;
                    TMR1 = 0;
                    IFS0bits.T1IF = 0;
                    state = led1;
                } else if (PORTDbits.RD6 == 1 && next == 2) {
                    T1CONbits.TON = 0;
                    TMR1 = 0;
                    IFS0bits.T1IF = 0;
                    state = led2;
                } else if (PORTDbits.RD6 == 1 && next == 3) {
                    T1CONbits.TON = 0;
                    TMR1 = 0;
                    IFS0bits.T1IF = 0;
                    state = led3;
                }
                //                while(PORTDbits.RD6 == 0);
                break;

            case directionChange:
                T1CONbits.TON = 0;
                TMR1 = 0;
                IFS0bits.T1IF = 0;
                if (PORTDbits.RD6 == 1 && current == 2) {
                    state = led1;
                } else if (PORTDbits.RD6 == 1 && current == 3){
                    state = led2;
                } else if (PORTDbits.RD6 == 1 && current == 1) {
                    state = led3;
                }
                break;
        }
    }
    
    return 0;
}

//void __ISR(_TIMER_1_VECTOR, IPL3SRS) _T1Interrupt() {
//    IFS0bits.T1IF = 0;
//    T1CONbits.TON = 0;
//    TMR1 = 0;
//    state = directionChange;
//}


//void __ISR(_TIMER_2_VECTOR, IPL3SRS) _T2Interrupt(){
//    T2CONbits.TON = 0;
//    IFS0bits.T2IF = 0;
//    state = directionChange;
//}