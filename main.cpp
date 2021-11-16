#ifdef WIN32
#include <windows.h>
#else
#include "MFRC522.h"
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



int lightOn(int pin)
{
    if(wiringPiSetup()==-1)
    {
    return 0;
    }
    pinMode(pin,OUTPUT);    //Passe le GPIO selectionne en mode OUTPUT
    for(int i=1;i<3;i++)
    {
    digitalWrite(pin,1);    //Allume la LED
    delay(200);
    digitalWrite(pin,0);    //Eteint la LED
    delay(200);
    }
    return 0; 
}

int main(){
  char blueCard[9] = "5F97CB04";          //UID des cartes
  char whiteCard[9] = "A709A304";
  int redPin = 7;                         //Numero des GPIO sur lesquels 
  int greenPin = 0;                       //les LED sont branchées 
  MFRC522 mfrc;
  mfrc.PCD_Init();                        //Initialise le RFID

  while(1){
    // Look for a card
    if(!mfrc.PICC_IsNewCardPresent())
      continue;

    if( !mfrc.PICC_ReadCardSerial())
      continue;

    char test[9];
    sprintf(test,"%X", mfrc.uid);
    if(strcmp(test, blueCard) == 0){       //Recupere l'UID de la carde detectee et le compare avec ceux enregistres
      lightOn(redPin);                     //Allume la LED correspondante
    }
    else {
      lightOn(greenPin);
    }
    delay(1000);
  }
  return 0;
}

