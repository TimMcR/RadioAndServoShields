#include "Arduino.h"
#include "RF24Shield.h"

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

RF24Slave::RF24Slave()
{
    usingServoShield = false;
};

RF24Slave::RF24Slave(ServoShield newShield)
{
    shield = newShield;
    usingServoShield = true;
};
/*
void RF24Slave::openReadingPipe(const byte newAddress[6])
{
    radio.openReadingPipe(0, newAddress);
}
*/
void RF24Slave::init(const byte newAddress[6])
{
    radio.begin();
    radio.openReadingPipe(0, newAddress);
    radio.setPALevel(RF24_PA_MAX);
    radio.startListening();

    if(usingServoShield)
        shield.init();
}

void RF24Slave::readData()
{
    if(radio.available())
    {
        if(usingServoShield)
            shield.ledOn();
        radio.read(&data, sizeof(data));
    }
    delay(250);
    if(usingServoShield)
        shield.ledOff();
}

void RF24Slave::readData(ServoShieldData &newData)
{
     if(radio.available())
    {
        if(usingServoShield)
            shield.ledOn();
        radio.read(&data, sizeof(data));
        newData = data;
    }
    delay(250);
    if(usingServoShield)
        shield.ledOff();
}

void RF24Slave::useData()
{
    shield.useServoData(data);
}

RF24Master::RF24Master()
{

};

void RF24Master::init(const byte newAddress[6])
{
    radio.begin();
    radio.openWritingPipe(newAddress);
    radio.setPALevel(RF24_PA_MAX);
    radio.stopListening();
}

void RF24Master::sendData(ServoShieldData data)
{
    radio.write(&data, sizeof(data));
    delay(250);
}