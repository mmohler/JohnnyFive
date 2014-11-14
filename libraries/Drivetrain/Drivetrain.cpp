//
//  Drivetrain.cpp
//  
//
//  Created by Matthew Mohler on 10/29/14.
//
//
#include "Arduino.h"
#include "Dagu4Motor.h"
#include "Drivetrain.h"

Drivetrain::Drivetrain(Dagu4Motor FL, Dagu4Motor FR, Dagu4Motor BL, Dagu4Motor BR)
    : _FL(FL), _FR(FR), _BL(BL), _BR(BR) {

    stopMotors();
}

void Drivetrain::goFwd(int rate) {
//Rate = 0-255
    _FL.setSpeed(rate);
    _FR.setSpeed(rate);
    _BL.setSpeed(rate);
    _BR.setSpeed(rate);
}

void Drivetrain::goBkwd(int rate) {
//Rate = 0-255
    _FL.setSpeed(0-rate);
    _FR.setSpeed(0-rate);
    _BL.setSpeed(0-rate);
    _BR.setSpeed(0-rate);
}

void Drivetrain::turnL(int rate) {
//Rate = 0-255
    _FL.setSpeed(0-rate);
    _FR.setSpeed(rate);
    _BL.setSpeed(0-rate);
    _BR.setSpeed(rate);
}

void Drivetrain::turnR(int rate) {
//Rate = 0-255
    _FL.setSpeed(rate);
    _FR.setSpeed(0-rate);
    _BL.setSpeed(rate);
    _BR.setSpeed(0-rate);
}

void Drivetrain::setSpeeds(int FL, int FR, int BL, int BR) {
    _FL.setSpeed(FL);
    _FR.setSpeed(FR);
    _BL.setSpeed(BL);
    _BR.setSpeed(BR);
}

void Drivetrain::stopMotors() {
    _FL.setSpeed(0);
    _FR.setSpeed(0);
    _BL.setSpeed(0);
    _BR.setSpeed(0);
}