#include <QTRSensors.h>
#include <PinMap.h>
#include <Dagu4Motor.h>
#include <NewPing.h>
#include <NavPack.h>
#include <Timer.h>

#define Kp 0.95
#define Kd 4

NavPack nav = NavPack();

QTRSensorsRC qtrrc((unsigned char[]) {
  Pin::i1,Pin::i2,Pin::i3,Pin::i4,Pin::i5,Pin::i6,Pin::i7,Pin::i8},
  IR_SENS, 2500, Pin::iLed);

Dagu4Motor FLMotor(Pin::mtr_spd_FL, Pin::mtr_dir_FL);
Dagu4Motor FRMotor(Pin::mtr_spd_FR, Pin::mtr_dir_FR);

NewPing PingFF(Pin::u_trig_FF, Pin::u_echo_FF, 300);
NewPing PingFL(Pin::u_trig_FL, Pin::u_echo_FL, 300);
NewPing PingFR(Pin::u_trig_FR, Pin::u_echo_FR, 300);

unsigned int state = 0;
unsigned int sensorValues[IR_SENS];
int error = 0;
int lastError = 0;
int offset = 0;
boolean printed = false;


void setup() {
  delay(100);
  Serial.begin(9600);

  //Setup and Turn off LEDs
  pinMode(Pin::indLEDR, OUTPUT);
  pinMode(Pin::indLEDG, OUTPUT);
  digitalWrite(Pin::indLEDR, HIGH);
  digitalWrite(Pin::indLEDG, HIGH);
  
  //SETUP OF 8IR Module
  digitalWrite(Pin::indLEDR, LOW);
//  for (unsigned int i = 0; i<IR_SENS; i++) {
  for (unsigned int i = 0; i<250; i++) {
    qtrrc.calibrate();
//    qtrrc.calibratedMinimumOn[i] = IRminOn[i];
//    qtrrc.calibratedMaximumOn[i] = IRmaxOn[i];
//    qtrrc.calibratedMinimumOff[i] = IRminOff[i];
//    qtrrc.calibratedMaximumOff[i] = IRmaxOff[i];
  }
  digitalWrite(Pin::indLEDR, HIGH);
  //SETUP Pin Mode L&R IRs
  pinMode(Pin::infraL, INPUT_PULLUP);
  pinMode(Pin::infraR, INPUT_PULLUP);

  //SETUP Pin Mode, Go Btn & Maze Size Selector
  pinMode(Pin::goBtn,  INPUT_PULLUP);
  pinMode(Pin::mazeSizeA, INPUT_PULLUP);
  pinMode(Pin::mazeSizeB, INPUT_PULLUP); 
  
  Serial.println(nav.initMaze(digitalRead(Pin::mazeSizeA), digitalRead(Pin::mazeSizeB)));
  //Serial.println(nav.cell);
  //delay(100);
}

void loop() {
  stateIt();
  //turnRight();
  //delay(500);
}

void stateIt() {
  switch(state){
    case 0: //wait for go state;
      digitalWrite(Pin::indLEDG, LOW);
      state = digitalRead(Pin::goBtn) ? state : state+1;
      break;
    case 1: //mapping maze;
       //Signify that we are mapping
      if ( map_maze(1) ) { 
        state += 2;
        digitalWrite(Pin::indLEDR, LOW);
        nav.solved = true;
      }
      break;
    case 2: //Re-Map/Image Grabs
      turnLeft();
      turnLeft();
      nav.orientation = 3;
      if ( map_maze(2) ) {
        state += 1;
        
      }
      break;
    case 3: //wait to trace critical path;
      state = digitalRead(Pin::goBtn) ? state : state+1;
      if (!printed) {
        for (unsigned int i = 0; i<25; i++) {
          Serial.println(nav._cells[i]);
        }
        printed = true;
        delay(5000);
        digitalWrite(Pin::indLEDR, HIGH);
        digitalWrite(Pin::indLEDG, LOW);
      }
      break;
    case 4: //Trace the critical path
      //turnLeft();
      //turnLeft();
      nav.orientation = 1;
       //Signify that we are tracing
      if( trace_path() )
        state += 1;
        digitalWrite(Pin::indLEDR, LOW);
        delay(2000);
      break;
    case 5:
      digitalWrite(Pin::indLEDG, HIGH);
      digitalWrite(Pin::indLEDR, HIGH);
      delay(500);
      digitalWrite(Pin::indLEDG, LOW);
      digitalWrite(Pin::indLEDR, LOW);
      delay(500);
      break;
  }
}

boolean map_maze(unsigned int phase) {
  boolean solved = false;
  while (!solved) {
    //continue solving - internal state machine;
    Serial.print(" Cell:");
    Serial.println(nav.cell);
    if (PingFR.ping() != 0 && PingFR.ping_in() < 5) { //If there is a wall to the right
      if (PingFF.ping() != 0 && PingFF.ping_in() < 5) { //And if there is a wall in front of us
        triggerImg(nav.cell);
        turnLeft();
        nav.recordMove('L');
      }
      else { //If there is a wall to the right, but not in front
        triggerImg(nav.cell);
        driveForward(true);
        nav.recordMove('F');
      }
    }
    else { //if there is not a wall to our right
      turnRight();
      nav.recordMove('R');
      driveForward(true);
      nav.recordMove('F');
    }
    if (phase == 2)
      solved = nav.atStartCell();
    else
      solved = nav.atEndCell();
    delay(50);
  }
  return true;
}

boolean trace_path() {
  boolean traced = false;
  char nextMove = 'O';
  while (!traced) {
    nextMove = nav.getNextMove();
    if (nextMove == 'D') {
      traced = true;
      break;
    }
    Serial.print(nav._index2);
    Serial.print(nextMove);
    Serial.println(nav.orientation);
    switch(nextMove) {
      case 'N':
        while(nav.orientation2 != 1) {
          if (nav.orientation2 == 4) {
            turnRight();
            nav.traceOrient('R');
            continue;
          }
          turnLeft();
          nav.traceOrient('L');
          Serial.print('L');
          Serial.println(nav.orientation2);
        }
        driveForward(true);
        break;
      case 'E':
        while(nav.orientation2 != 2) {
          if (nav.orientation2 == 1) {
            turnRight();
            nav.traceOrient('R');
            continue;
          }
          turnLeft();
          nav.traceOrient('L');
          Serial.print('L');
          Serial.println(nav.orientation2);
        }
        driveForward(true);
        break;
      case 'S':
        while(nav.orientation2 != 3) {
          if (nav.orientation2 == 2) {
            turnRight();
            nav.traceOrient('R');
            continue;
          }
          turnLeft();
          nav.traceOrient('L');
          Serial.print('L');
          Serial.println(nav.orientation2);
        }
        driveForward(true);
        break;
      case 'W':
        while(nav.orientation2 != 4) {
          if (nav.orientation2 == 3) {
            turnRight();
            nav.traceOrient('R');
            continue;
          }
          turnLeft();
          nav.traceOrient('L');
          Serial.print('L');
          Serial.println(nav.orientation2);
        }
        driveForward(true);
        break;
    }
  }
  return true;
}

void driveForward(boolean timed) {
  FLMotor.setSpeed(60);
  FRMotor.setSpeed(60);
  Timer t1(500);
  if (!timed) {
    t1.startTimer(0);
  }
  while (true) {
    //Get IR Position;
    offset = pidDrive();
    //Set Speeds
    if (!t1.isTimeExpired()) {
      FLMotor.setSpeed(70 + offset);
      FRMotor.setSpeed(70 - offset);
    }
    else {
      FLMotor.setSpeed(50 + offset);
      FRMotor.setSpeed(50 - offset);
    }
    if (PingFF.ping_in() < 3 && PingFF.ping_in() != 0) {
      break; //Front Sensor is failsafe.
    }
    if (t1.isTimeExpired() && (digitalRead(Pin::infraL) && digitalRead(Pin::infraR))) {
      break; //When line found
    }
  }
  FLMotor.setSpeed(0);
  FRMotor.setSpeed(0);
  delay(75);
  FLMotor.setSpeed(-40);
  FRMotor.setSpeed(-40);
  delay(350);
  FLMotor.setSpeed(0);
  FRMotor.setSpeed(0);
}

void turnLeft() {
  FLMotor.setSpeed(-40);
  FRMotor.setSpeed(40);
  delay(790);
  lastError = 0;
  FLMotor.setSpeed(0);
  FRMotor.setSpeed(0);
  delay(100);
  //while (qtrrc.readLine(sensorValues) < 2000 || qtrrc.readLine(sensorValues) > 5000) {
  //  delay(5);
  //}
  driveForward(false);
}

void turnRight() {
  FLMotor.setSpeed(40);
  FRMotor.setSpeed(-40);
  delay(790);
  lastError = 0;
  FLMotor.setSpeed(0);
  FRMotor.setSpeed(0);
  delay(100);
  //while (qtrrc.readLine(sensorValues) < 2000 || qtrrc.readLine(sensorValues) > 5000) {
  //  delay(5);
  //}
  driveForward(false);
}

void triggerImg(unsigned int cell) {
  //Serial.print('IMG,');
  //Serial.println(cell);
  /*
  while (!(Serial.available > 0)) {
    delay(10);
  }
  if (Serial.read() == 0)
    return;
  //else flag error somehow 
  */
}

int pidDrive() {
  unsigned int position = qtrrc.readLine(sensorValues); // get calibrated readings along with the line position
  error = position/100 - 35;
  int motorSpeed = Kp * error + Kd * (error - lastError); //Ki is not really needed for line following, Kd should be much bigger than Kp since the derivative of the error is much smaller than the error itself, so to be useful, it should be large
  lastError = error;

  if (motorSpeed > 20) {
    motorSpeed = 20;
  }
  if (motorSpeed < -20) {
    motorSpeed = -20;
  }
  return motorSpeed;
}


