#ifndef RF24Shield_h
#define RF24Shield_h

#ifndef nRF24L01_h
#include "nRF24L01.h"
#endif

#ifndef RF24_h
#include "RF24.h"
#endif

#ifndef RF24_config_h
#include "RF24_config.h"
#endif

#ifndef RadioStructs_h
#include "RadioStructs.h"
#endif

#ifndef ServoShield_h
#include "ServoShield.h"
#endif

class RF24Slave
{
    private:

        RF24 radio = RF24(7, 8);
        boolean usingServoShield; 

    public:
    
        
        RF24Slave();
        RF24Slave(ServoShield newShield);
        //void openReadingPipe(const byte newAddress[6]);
        void init(const byte newAddress[6]);
        void readData();
        void readData(ServoShieldData &newData);
        void useData();
        ServoShield shield;
        ServoShieldData data;
};

class RF24Master
{
    private:

        RF24 radio = RF24(7, 8);

    public:

        RF24Master();
        void init(const byte newAddress[6]);
        void sendData(ServoShieldData data);
};

#endif