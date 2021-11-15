#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#endif

void delay(int ms){
#ifdef WIN32
  Sleep(ms);
#else
  usleep(ms*1000);
#endif
}

#include "MFRC522.h"

int lightOn(int pin)
{
    if(wiringPiSetup()==-1)
    {
    return 0;
    }
    pinMode(pin,OUTPUT);
    for(int i=1;i<3;i++)
    {
    digitalWrite(pin,1);
    delay(500); //on attend 500ms
    digitalWrite(pin,0);
    delay(500);
    }
    return 0;
}

int main(){
  char blueCard[9] = "5F97CB04";
  char whiteCard[9] = "A709A304";
  int redPin = 7;
  int greenPin = 11;
  MFRC522 mfrc;
  mfrc.PCD_Init();

  while(1){
    // Look for a card
    if(!mfrc.PICC_IsNewCardPresent())
      continue;

    if( !mfrc.PICC_ReadCardSerial())
      continue;

    // Print UID
    char test[9];
    sprintf(test,"%X", mfrc.uid);
    if(strcmp(test, blueCard) == 0){
      lightOn(redPin);
    }
    else {
      lightOn(greenPin);
    }
    delay(1000);
  }
  return 0;
}

