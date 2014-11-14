//
//  Drivetrain.h
//  
//
//  Created by Matthew Mohler on 10/29/14.
//
//


#ifndef Drivetrain_h
#define Drivetrain_h

#include "Arduino.h"
#include "Dagu4Motor.h"

class Drivetrain {
public:
    Drivetrain(Dagu4Motor FL, Dagu4Motor FR, Dagu4Motor BL, Dagu4Motor BR);
    void goFwd(int rate);
    void goBkwd(int rate);
    void turnL(int rate);
    void turnR(int rate);
    void setSpeeds(int FL, int FR, int BL, int BR);
    void stopMotors();
    
private:
    //MOTORS
    Dagu4Motor _FL;
    Dagu4Motor _FR;
    Dagu4Motor _BL;
    Dagu4Motor _BR;
    
};

#endif
