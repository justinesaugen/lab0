/* 
 * File:   timer.c
 * Author: Justine Saugen
 *
 * Created on September 14, 2015, 3:34 PM
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0;
    PR1 = 2441;
    T1CONbits.TCKPS = 3;
    T1CONbits.TCS = 0;
//    IEC0bits.T1IE = 1;
//    IFS0bits.T1IF = 0;
//    IPC1bits.T1IP = 3;
    T1CONbits.TON = 0;
}

initTimer2(){
    //TODO: Initialize Timer 2.
    TMR2 = 0;
    PR2 = 2441;
    T2CONbits.TCKPS = 3;
    T2CONbits.TCS = 0;
//    IEC0bits.T2IE = 1;
//    IFS0bits.T2IF = 0;
//    IPC2bits.T2IP = 2;
    T2CONbits.TON = 0;
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
    TMR2 = 0;
    PR2 = delay * PR2;
    
    IFS0bits.T2IF = 0;
    T2CONbits.TON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.TON = 0;
    
}