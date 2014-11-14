#include <Arduino.h>
#include <PinMap.h>

void setup() {
  pinMode(Pin::infra_L, INPUT_PULLUP);
  pinMode(Pin::infra_R, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("HELLO!");
}

void loop() {
  Serial.print("L: ");
  Serial.print((int)digitalRead(Pin::infra_L));
  Serial.print(" | R: ");
  Serial.print((int)digitalRead(Pin::infra_R));
  Serial.println();
  delay(500);
}
  
