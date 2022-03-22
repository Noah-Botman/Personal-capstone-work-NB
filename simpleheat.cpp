/* 'Noah'
 * File:   simpleheat.cpp
 * Github: Noah-Botman
 *
 * Created on March, 2022
 */

#include <commonLib.h>
#include <cstdlib>

using namespace std;


void main(void) {
    TRISAbits.RA2=0; //pin 09 set as output (left side heating pads)
    TRISAbits.RA3=0; //pin 10 set as output (central heating pads)
    TRISAbits.RA4=0; //pin 11 set as output (right side heating pads
  
    TRISBbits.RB7=1; //pin 16 set as input (boss control)
    TRISBbits.RB8=1; //pin 16 set as input (interupts)
  
    int run = 0;
    int left = 1;
    int right = 0;
    int mid = 0;
    int heat = 1;
    int initheat = 0;
    
    while(1){
        if(PORTBbits.RB7==1){
            __delay_ms(100);
            run = run + 1; //logical inputs from boss can change the run variable, switching the task of the microcontroller
            if(run>=8){
                run = 0; //makes sure run only cycles between 0 and 7
                left = 0;
                right = 0;
                mid = 0;
            }
            if(run==1){
                left = 1;
                right = 0;
                mid = 0;
            }
            if(run==2){
                left = 0;
                right = 1;
                mid = 0;
            }
            if(run==3){
                left = 0;
                right = 0;
                mid = 1;
            }
            if(run==4){
                left = 1;
                right = 1;
                mid = 0;
            }
            if(run==5){
                left = 1;
                right = 0;
                mid = 1;
            }
            if(run==6){
                left = 0;
                right = 1;
                mid = 1;
            }
            if(run==7){
                left = 1;
                right = 1;
                mid = 1;
            }
        }
    }
    
    while(1){
        if(PORTBbits.RB8==1){
            __delay_ms(100);
            heat = heat + 1; //logical inputs from boss can change the heat variable
            if(heat>=4){
                heat = 0; //makes sure run only cycles between 0 and 3
            }
        }
    }
    
    while(left==1){
        if(heat==1){
            __delay_ms(500);
            LATAbits.RA2=1;
            __delay_ms(500);
            LATAbits.RA2=0;
        }
        if(heat==2){
            __delay_ms(660);
            LATAbits.RA2=1;
            __delay_ms(340);
            LATAbits.RA2=0;
        }
        if(heat==3){
            __delay_ms(750);
            LATAbits.RA2=1;
            __delay_ms(250);
            LATAbits.RA2=0;
        }
    }
    
    while(mid==1){
        if(heat==1){
            __delay_ms(500);
            LATAbits.RA3=1;
            __delay_ms(500);
            LATAbits.RA3=0;
        }
        if(heat==2){
            __delay_ms(660);
            LATAbits.RA3=1;
            __delay_ms(340);
            LATAbits.RA3=0;
        }
        if(heat==3){
            __delay_ms(750);
            LATAbits.RA3=1;
            __delay_ms(250);
            LATAbits.RA3=0;
        }
    }
    
    while(right==1){
        if(heat==1){
            __delay_ms(500);
            LATAbits.RA4=1;
            __delay_ms(500);
            LATAbits.RA4=0;
        }
        if(heat==2){
            __delay_ms(660);
            LATAbits.RA4=1;
            __delay_ms(340);
            LATAbits.RA4=0;
        }
        if(heat==3){
            __delay_ms(750);
            LATAbits.RA4=1;
            __delay_ms(250);
            LATAbits.RA4=0;
        }
    }
       
            
    return 0;
}
