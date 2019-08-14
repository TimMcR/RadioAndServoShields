#ifndef ServoShield_h
#define ServoShield_h

#include "Arduino.h"

#ifndef Servo_h
#include "Servo.h"
#endif

#ifndef LED_h
#include "LED.h"
#endif

#ifndef RadioStructs_h
#include "RadioStructs.h"
#endif


class ServoShield
{
  private:

    Servo servo1;
    Servo servo2;
    Servo servo3;
    Servo servo4;
    Servo servo5;
    Servo allServos[5] = {servo1, servo2, servo3, servo4, servo5};
    

  public:
    
    ServoShield();
    void writeToServo(int servo, int pos);
    void writeServo1(int pos);
    void writeServo2(int pos);
    void writeServo3(int pos);
    void writeServo4(int pos);
    void writeServo5(int pos);

    void init();
    void ledOn();
    void ledOff();
    void useServoData(ServoShieldData data);
    
    LED led = LED(9);
};

#endif