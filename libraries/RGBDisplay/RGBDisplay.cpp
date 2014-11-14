//
//  RGBDisplay.cpp
//  
//
//  Created by Matthew Mohler on 11/3/14.
//
//

#include <LiquidCrystal.h>
#include "RGBDisplay.h"
#include "Arduino.h"

RGBDisplay::RGBDisplay(LiquidCrystal lcd, int pBlR, int pBlG, int pBlB)
    : _lcd(lcd), _BlR(pBlR), _BlG(pBlG), _BlB(pBlB) {
    init();
}

void RGBDisplay::init() {
    pinMode(_BlR, OUTPUT);
    pinMode(_BlG, OUTPUT);
    pinMode(_BlB, OUTPUT);
    _lcd.begin(16, 2);
    write("INITIALIZING");
}

void RGBDisplay::setPosition(int row, int column) {
    _lcd.setCursor(0, 1);
}
void RGBDisplay::write(String text) {
    _lcd.print(text);
}
void RGBDisplay::setBacklight(int rVal, int gVal, int bVal) {
    analogWrite(_BlR,rVal);
    analogWrite(_BlG,gVal);
    analogWrite(_BlB,bVal);
}