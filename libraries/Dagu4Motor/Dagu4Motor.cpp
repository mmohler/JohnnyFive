/*
 Dagu4Motor.cpp - Library for driving the Dagu4Motor Driver code.
 Created by William Garrdio
 Created on: 02/03/2012
 02/25/2012 - Rewrite class to handle 1 motor per instance
 11/24/2013 - Removed Teensy Encoder library, better if called from Sketch
 
 */
#include <Dagu4Motor.h>

Dagu4Motor::Dagu4Motor(int pwmPin, int dirPin)
{
    _pwm = pwmPin;
    _dir = dirPin;
    _speed = 0;
    _rev = false;
    pinMode(_pwm, OUTPUT);
    pinMode(_dir, OUTPUT);
}

Dagu4Motor::Dagu4Motor(int pwmPin, int dirPin, bool rev)
{
    _pwm = pwmPin;
    _dir = dirPin;
    _speed = 0;
    _rev = rev;
    pinMode(_pwm, OUTPUT);
    pinMode(_dir, OUTPUT);
}

void Dagu4Motor::setSpeed(int speedMotor)
{
    if (_rev) {speedMotor = -speedMotor;}
    
    if (speedMotor < 0) {
        digitalWrite(_dir, LOW);  //Set motor direction, 1 low, 2 high
    }
    else {
        digitalWrite(_dir, HIGH);  //Reverse motor direction, 1 high, 2 low
    }
    
    speedMotor = abs(speedMotor);
    
    analogWrite(_pwm, speedMotor);
    _speed=speedMotor;
    
}

int Dagu4Motor::getSpeed()
{
    return _speed;
}



