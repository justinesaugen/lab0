/* 
 * File:   switch.c
 * Author: Justine Saugen
 *
 * Created on September 14, 2015, 3:34 PM
 */

#include <xc.h>
#define INPUT 1
#define OUTPUT 0

void initSwitch1(){
    TRISDbits.TRISD6 = INPUT;
    //CNENDbits.CNIED6 = 1;
    CNPUDbits.CNPUD6 = INPUT;
    //IEC1bits.CNDIE = 1;
//    CNCONDbits.ON = 1;

    
    
    //TODO: Initialize switch 1
}