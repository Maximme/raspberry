#include <stdio.h>
#include <wiringPi.h>


int main(void)
{
    int pinRed = 7;
    if(wiringPiSetup()==-1)
    {
    return 0;
    }
    pinMode(pinRed,OUTPUT);
    for(int i=1;i<20;i++)
    {
    digitalWrite(pinRed,1);
    delay(500); //on attend 500ms
    digitalWrite(pinRed,0);
    delay(500);
    }
    return 0;
}