#ifndef FlipRfid_H
#define FlipRfid_H
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"

#endif

#define SS_PIN 8
#define RST_PIN 4

class FlipRfid
{
    public:
            FlipRfid();
            void readRfid();
		        String* getRfid();
            void initRfid();
    private:
           //String _cardNum;
          

};

#endif
