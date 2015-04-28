//
//  Timer.h
//  
//
//  Created by Matthew Mohler on 3/8/15.
//
//

#include <Arduino.h>

#ifndef Timer_h
#define Timer_h

class Timer {
public:
    Timer(void);
    Timer(unsigned int time);
    
    void startTimer(unsigned int time);
    
    long timeRemaining();
    long timeElapsed();
    
    bool isTimeExpired();
    
private:
    long _startTime, _endTime;
};


#endif /* defined(____Timer__) */
