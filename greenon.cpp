#include <stdio.h>
#include <wiringPi.h>
#include "greenon.h"

int greenon(void)
{
    int pinGreen = 7;
    if(wiringPiSetup()==-1)
    {
    return 0;
    }
    pinMode(pinGreen,OUTPUT);
    for(int i=1;i<20;i++)
    {
    digitalWrite(pinGreen,1);
    delay(500); //on attend 500ms
    digitalWrite(pinGreen,0);
    delay(500);
    }
    return 0;
}