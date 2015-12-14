#include "Arduino.h"
#include "FlipRfid.h"
#include "RFID.h"
            
RFID rfid(SS_PIN, RST_PIN);
String cardNum;
unsigned long readID;
FlipRfid::FlipRfid()
{
}

void FlipRfid::initRfid()
{
  rfid.init();
}

String* FlipRfid::getRfid()
{ 
  cardNum = String('\0'); 
  readRfid();
	
  if (cardNum != '\0')//if string cardNum is not empty, print the value
 {
    //Serial.println(cardNum);
  //delay(500); 
 }
 return(&cardNum);
}


void FlipRfid::readRfid()
{
  //unsigned long readID;
  if (rfid.isCard())
  {
    if (rfid.readCardSerial())
    {
      for (int i=0; i<=4; i++)//card value: "xyz xyz xyz xyz xyz" (15 digits maximum; 5 pairs of xyz)hence 0<=i<=4 //
      {
        readID = rfid.serNum[i];
        cardNum += readID; // store RFID value into string "cardNum" and concatinate it with each iteration
      }
    }
  }
  rfid.halt();
}
/*if (cardNum != '\0')
 {
    //Serial.println("card found");
    //Serial.println(cardNum);
    String x = cardNum;
    cardNum.remove(0);
    rfid.reset();
    return (x);
    
    delay(500); 
 }
}*/
