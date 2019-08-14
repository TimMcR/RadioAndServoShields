#include "Arduino.h"
#include "ServoShield.h"

#ifndef Servo_h
#include "Servo.h"
#endif

#ifndef LED_h
#include "LED.h"
#endif



ServoShield::ServoShield()
{

};

void ServoShield::init()
{
servo1.attach(2);   
servo2.attach(3);  
servo3.attach(4);  
servo4.attach(5);  
servo5.attach(6); 
}

void ServoShield::writeToServo(int servo, int pos)
{
allServos[servo].write(pos);
}

void ServoShield::writeServo1(int pos)
{
servo1.write(pos);
}

void ServoShield::writeServo2(int pos)
{
servo2.write(pos);
}

void ServoShield::writeServo3(int pos)
{
servo3.write(pos);
}

void ServoShield::writeServo4(int pos)
{
servo4.write(pos);
}

void ServoShield::writeServo5(int pos)
{
servo5.write(pos);
}

void ServoShield::ledOn()
{
    led.on();
}

void ServoShield::ledOff()
{
    led.off();
}

void ServoShield::useServoData(ServoShieldData data)
{
    writeServo1(data.servo1Pos);
    writeServo2(data.servo2Pos);
    writeServo3(data.servo3Pos);
    writeServo4(data.servo4Pos);
    writeServo5(data.servo5Pos);
}