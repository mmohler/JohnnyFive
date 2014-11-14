#include <Arduino.h>
#include <NewPing.h>
#include <PinMap.h>

int MAX_PING_DISTANCE = 300;
int uS_Time;

NewPing PingFF(Pin::u_trig_FF, Pin::u_echo_FF, MAX_PING_DISTANCE);
NewPing PingFL(Pin::u_trig_FL, Pin::u_echo_FL, MAX_PING_DISTANCE);
NewPing PingFR(Pin::u_trig_FR, Pin::u_echo_FR, MAX_PING_DISTANCE);
NewPing PingBL(Pin::u_trig_BL, Pin::u_echo_BL, MAX_PING_DISTANCE);
NewPing PingBR(Pin::u_trig_BR, Pin::u_echo_BR, MAX_PING_DISTANCE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(1000);
  uS_Time = PingFF.ping();
  Serial.print("PingFF: ");
  Serial.print(uS_Time / US_ROUNDTRIP_IN);
  Serial.println("in");

  uS_Time = PingFL.ping();
  Serial.print("PingFL: ");
  Serial.print(uS_Time / US_ROUNDTRIP_IN);
  Serial.println("in");

  uS_Time = PingFR.ping();
  Serial.print("PingFR: ");
  Serial.print(uS_Time / US_ROUNDTRIP_IN);
  Serial.println("in");

  uS_Time = PingBL.ping();
  Serial.print("PingBL: ");
  Serial.print(uS_Time / US_ROUNDTRIP_IN);
  Serial.println("in");  

  uS_Time = PingBR.ping();
  Serial.print("PingBR: ");
  Serial.print(uS_Time / US_ROUNDTRIP_IN);
  Serial.println("in");
  
  Serial.println();
}

