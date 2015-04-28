#include <PinMap.h>
#include <Dagu4Motor.h>
#include <Arduino.h>
#include <NewPing.h>

int started=0;
int spdL,spdR,dist, uStime;
int d1,d2;
int MAX_PING_DISTANCE = 300;

Dagu4Motor FLMotor = Dagu4Motor(Pin::mtr_spd_FL, Pin::mtr_dir_FL, true);
Dagu4Motor FRMotor = Dagu4Motor(Pin::mtr_spd_FR, Pin::mtr_dir_FR, false);

NewPing PingFF(Pin::u_trig_FF, Pin::u_echo_FF, MAX_PING_DISTANCE);
NewPing PingFL(Pin::u_trig_FL, Pin::u_echo_FL, MAX_PING_DISTANCE);
NewPing PingFR(Pin::u_trig_FR, Pin::u_echo_FR, MAX_PING_DISTANCE);
NewPing PingRL(Pin::u_trig_BL, Pin::u_echo_BL, MAX_PING_DISTANCE);
NewPing PingRR(Pin::u_trig_BR, Pin::u_echo_BR, MAX_PING_DISTANCE);

void setup() {
  Serial.begin(115200);
  spdL = spdR = 60;
  pinMode(Pin::goBtn, INPUT_PULLUP);
  pinMode(Pin::infra_LL, INPUT_PULLUP);
  pinMode(Pin::infra_RR, INPUT_PULLUP);
  pinMode(Pin::infra_L, INPUT_PULLUP);
  pinMode(Pin::infra_R, INPUT_PULLUP);
}

void loop() {
  while(!started) {
    started = !digitalRead(Pin::goBtn);
    spdL=spdR=50;
    delay(10);
  }
  if(digitalRead(Pin::infra_L)) {
    spdL -= 2;
  }
  else if(digitalRead(Pin::infra_R)) {
    spdL += 2;
  }
  else if(!digitalRead(Pin::infra_L) && !digitalRead(Pin::infra_R)) {
    spdL =50;
  }

  if(spdL < 30) {spdL = 30;}
  if(spdL > 90) {spdL = 90;}
    
  FLMotor.setSpeed(spdL+20);
  FRMotor.setSpeed(spdR);
  uStime = PingFF.ping();
  dist = (uStime / US_ROUNDTRIP_IN);
  if(dist<5){ //|| (digitalRead(Pin::infra_LL) && digitalRead(Pin::infra_RR))) {
    FLMotor.setSpeed(0);
    FRMotor.setSpeed(0);
    started = 0;
    delay(100);
    FLMotor.setSpeed(-98);
    FRMotor.setSpeed(-70);
    delay(300);
    FLMotor.setSpeed(-98);
    FRMotor.setSpeed(70);
    delay(400);
    FLMotor.setSpeed(98);
    FRMotor.setSpeed(70);
    delay(200);
    FLMotor.setSpeed(-108);
    FRMotor.setSpeed(80);
    d1 = PingFR.ping()/US_ROUNDTRIP_IN;
    d2 = PingRR.ping()/US_ROUNDTRIP_IN;
    while(d1 != d2) {
      delay(10);
      d1 = PingFR.ping()/US_ROUNDTRIP_IN;
      d2 = PingRR.ping()/US_ROUNDTRIP_IN;
    }
    FLMotor.setSpeed(68);
    FRMotor.setSpeed(40);
    //delay(4000);
    delay(1000);
    FLMotor.setSpeed(0);
    FRMotor.setSpeed(0);
  }
  delay(50);
}
