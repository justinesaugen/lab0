/* 
 * File:   led.c
 * Author: Justine Saugen
 *
 * Created on September 14, 2015, 3:34 PM
 */

#include <xc.h>
#include "led.h"
#define OUTPUT 0
#define INPUT 1

void initLEDs(){
    TRISDbits.TRISD0 = OUTPUT;
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
    LATDbits.LATD0 = 0;
    LATDbits.LATD1 = 0;
    LATDbits.LATD2 = 0;
    //TODO: Initialize LEDs
}

void turnOnLED(int led){
    
    
    switch(led){
        case 1:{
            LATDbits.LATD0 = 1;
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
            break;
        }
        case 2:{
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 1;
            LATDbits.LATD2 = 0;
            break;
        }
        case 3:{
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 1;
            break;
        }        
    }
    //TODO: You may choose to write this function
    // as a matter of convenience
    
}