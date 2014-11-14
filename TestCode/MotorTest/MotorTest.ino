#include <PinMap.h>
#include <Dagu4Motor.h>

//signed int val;
String inString;
Dagu4Motor FLMotor = Dagu4Motor(Pin::mtr_spd_FL, Pin::mtr_dir_FL);
Dagu4Motor FRMotor = Dagu4Motor(Pin::mtr_spd_FR, Pin::mtr_dir_FR);
Dagu4Motor BLMotor = Dagu4Motor(Pin::mtr_spd_BL, Pin::mtr_dir_BL);
Dagu4Motor BRMotor = Dagu4Motor(Pin::mtr_spd_BR, Pin::mtr_dir_BR);

//Pins.mtr_dir_FL

void setup () {
  //Serial.begin(9600);
  //val = 0;
  
}

void loop() {
    FLMotor.setSpeed(-255);
    FRMotor.setSpeed(-255);
    BLMotor.setSpeed(-255);
    BRMotor.setSpeed(-255);
    //Serial.println(FLMotor.getSpeed());
  //lMotor.setSpeed(lSpeed);
  //rMotor.setSpeed(rSpeed);
}
