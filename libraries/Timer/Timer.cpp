//
//  Timer.cpp
//  
//
//  Created by Matthew Mohler on 3/8/15.
//
//

#include "Timer.h"

Timer::Timer(void) {
    _startTime = millis();
    _endTime = millis();
}

Timer::Timer(unsigned int time) {
    _startTime = millis();
    _endTime = millis() + time;
}

void Timer::startTimer(unsigned int time) {
    _startTime = millis();
    _endTime = millis() + time;
}


long Timer::timeRemaining() {
    return _endTime - millis();
}

long Timer::timeElapsed() {
    return millis() - _startTime;
}

bool Timer::isTimeExpired() {
    return millis() > _endTime;
}