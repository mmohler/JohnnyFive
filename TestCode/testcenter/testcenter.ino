#include <Arduino.h>
#include <NewPing.h>
#include <PinMap.h>
#include <Dagu4Motor.h>
#include <Drivetrain.h>

int MAX_PING_DISTANCE = 300;
int uS_Time, spdR, spdL;
int us_fl, us_fr, us_bl, us_br, us_ff;
int us_lAvg, us_rAvg;

int started=0;

NewPing PingFF(Pin::u_trig_FF, Pin::u_echo_FF, MAX_PING_DISTANCE);
NewPing PingFL(Pin::u_trig_FL, Pin::u_echo_FL, MAX_PING_DISTANCE);
NewPing PingFR(Pin::u_trig_FR, Pin::u_echo_FR, MAX_PING_DISTANCE);
NewPing PingBL(Pin::u_trig_BL, Pin::u_echo_BL, MAX_PING_DISTANCE);
NewPing PingBR(Pin::u_trig_BR, Pin::u_echo_BR, MAX_PING_DISTANCE);

Dagu4Motor FLMotor = Dagu4Motor(Pin::mtr_spd_FL, Pin::mtr_dir_FL);
Dagu4Motor FRMotor = Dagu4Motor(Pin::mtr_spd_FR, Pin::mtr_dir_FR);
Dagu4Motor BLMotor = Dagu4Motor(Pin::mtr_spd_BL, Pin::mtr_dir_BL);
Dagu4Motor BRMotor = Dagu4Motor(Pin::mtr_spd_BR, Pin::mtr_dir_BR);
Drivetrain drive = Drivetrain(FLMotor, FRMotor, BLMotor, BRMotor);

void setup() {
  spdL=spdR=60;
  delay(2000);
  Serial.begin(115200);
  Serial.println("ML,MR,USl,USr,USf");
  pinMode(Pin::goBtn, INPUT_PULLUP);
}

void loop() {
  while (!started) {
    started = !digitalRead(Pin::goBtn);
  }
  spdL=spdR=60;
  us_fl = PingFL.ping()/US_ROUNDTRIP_CM;
  us_fr = PingFR.ping()/US_ROUNDTRIP_CM;
  us_ff = PingFF.ping()/US_ROUNDTRIP_CM;
  us_bl = PingBL.ping()/US_ROUNDTRIP_CM;
  us_br = PingBR.ping()/US_ROUNDTRIP_CM;
  
  us_lAvg = (us_fl + us_bl)/2;
  us_rAvg = (us_fr + us_br)/2;  
  
  //if ((us_bl + 3) < us_br) {
  //  spdL = 100 + (us_rAvg-us_lAvg)/4;
  //  spdR = 100 - (us_rAvg-us_lAvg)/4;
  //}
  //else if ((us_bl + 3) > us_br) {
  //  spdL = 100 - (us_lAvg-us_rAvg)/4;
  //  spdR = 100 + (us_lAvg-us_rAvg)/4;    
  //}
  Serial.print(spdL); Serial.print(',');
  Serial.print(spdR); Serial.print(',');
  Serial.print(us_lAvg); Serial.print(',');
  Serial.print(us_rAvg); Serial.print(',');
  Serial.println(us_ff);
  if ((us_ff != 0) && (us_ff < 18)) {
    spdL = -50;
    spdR = -50;
    drive.setSpeeds(spdL, spdL, spdL, spdL);
    delay(75);
    spdL = 0;
    spdR = 0;
    drive.setSpeeds(spdL, spdL, spdL, spdL);
    started = false; 
  }
  drive.setSpeeds(spdL, spdL, spdL, spdL);
}
