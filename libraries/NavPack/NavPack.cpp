//
//  NavPack.cpp
//  
//
//  Created by Matthew Mohler on 2/26/15.
//
//


/* Direction MAP
 
        1
        |
        |
  4-----0-----2
        |
        |
        3
 
*/

#include "NavPack.h"

NavPack::NavPack() {
    cell = 0;
    orientation = 1;
    orientation2 = 1;
    solved = false;
    _cells[0] = 0;
    _index = _index2 = 0;
}

void NavPack::recordMove(char dir) {
    if (!solved) {
        switch (dir) {
            case 'F':
                switch(orientation) {
                    case 1:
                        cell -= 7;
                        break;
                    case 2:
                        cell += 1;
                        break;
                    case 3:
                        cell += 7;
                        break;
                    case 4:
                        cell -= 1;
                        break;
                }
                if (inArray(cell) == 0)
                    _cells[++_index] = cell;
                else
                    _index = inArray(cell);
                break;
            case 'L':
                if (orientation == 1)
                    orientation = 4;
                else
                    orientation -= 1;
                break;
            
            case 'R':
                if (orientation == 4)
                    orientation = 1;
                else
                    orientation += 1;
                break;
        }
    }
    
}
void NavPack::traceOrient(char dir) {
    switch (dir) {
        case 'L':
            if (orientation2 == 1)
                orientation2 = 4;
            else
                orientation2 -= 1;
            break;
                
        case 'R':
            if (orientation2 == 4)
                orientation2 = 1;
            else
                orientation2 += 1;
            break;
    }
}

int NavPack::initMaze(int a, int b) {
    if (!a && b) {
        _size = 5;
    }
    else if (a && b) {
        _size = 6;
    }
    else if (a && !b)
        _size = 7;
    
    switch(_size) {
        case 5:
            _startCell = 48;
            _stopCell = 9; //should be 9
            break;
        case 6:
            _startCell = 48;
            _stopCell = 1;
            break;
        case 7:
            _startCell = 49;
            _stopCell = 1;
            break;
    }
    _cells[0] = _startCell;
    cell = _startCell;
    return _size;
}

int NavPack::getCell() {
    return cell;
}

void NavPack::generateCritical() {

}

unsigned char NavPack::getNextMove() {
    int temp = 0;
    if ( (_index2 == _index) || (_cells[_index2]==0) )
        return 'D'; //FOR DONE!!!!
    
    temp = _cells[_index2+1] - _cells[_index2];
    _index2++;
    switch(temp) {
        case -7: //Need to go North
            return 'N';
            break;
        case -1: //Need to go West
            return 'W';
            break;
        case 1: //Need to go East
            return 'E';
            break;
        case 7: //Need to go South
            return 'S';
            break;
    }
    
}

bool NavPack::atEndCell() {
    return (cell == _stopCell);
}

bool NavPack::atStartCell() {
    return (cell == _startCell);
}

unsigned int NavPack::inArray(unsigned int compCell) {
    for (unsigned int i = 0; i <= _index; i++) {
        if (_cells[i] == compCell)
            return i;
    }
    return 0;
}