#include "FlipRfid.h"
FlipRfid ab; // create an instance called asb for the class LDR.
String* x;
void setup()
{
  Serial.begin(9600);
  Serial.println("starting....");
  delay(1000);
  ab.initRfid();
  Serial.println("System Ready");
}

void loop()
{
  x=ab.getRfid();
  if (*x != '\0')
  {
  Serial.print("num: ");
  Serial.println(*x);
  delay(1000);
  }
}
  
