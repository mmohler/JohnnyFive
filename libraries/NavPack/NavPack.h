//
//  NavPack.h
//  
//
//  Created by Matthew Mohler on 2/26/15.
//
//

#include <String.h>

#ifndef NavPack_h
#define NavPack_h

class NavPack {
public:
    NavPack();
    void recordMove(char dir);
    void traceOrient(char dir);
    int initMaze(int a, int b);
    int getCell();
    void generateCritical();
    
    unsigned char getNextMove();
    
    bool atEndCell();
    bool atStartCell();
    
    unsigned int orientation,orientation2;
    unsigned int cell;
    bool solved;
    unsigned int _cells[50];
    unsigned int _index2, _index;
private:
    unsigned int inArray(unsigned int compCell);
    unsigned int _startCell, _stopCell, _size;
};


#endif /* defined(____NavPack__) */
