//
//  RGBDisplay.h
//  
//
//  Created by Matthew Mohler on 11/3/14.
//
//

#ifndef RGBDisplay_h
#define RGBDisplay_h

//#include "Arduino.h"
//#include <PinMap.h>
#include <LiquidCrystal.h>

class RGBDisplay {
public:
    RGBDisplay(LiquidCrystal lcd, int pBlR, int pBlG, int pBlB);
    void init();
    void setPosition(int row, int column);
    void write(String text);
    void setBacklight(int rVal, int gVal, int bVal);
    
private:
    //PINS
    LiquidCrystal _lcd;
    int _BlR;
    int _BlG;
    int _BlB;
};

#endif /* defined(RGBDisplay_h) */
