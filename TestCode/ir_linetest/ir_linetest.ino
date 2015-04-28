#include <Arduino.h>
#include <PinMap.h>
void setup() {
  pinMode(Pin::infraL, INPUT_PULLUP);
  pinMode(Pin::infraR, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("HELLO!");
}

void loop() {
  Serial.print(" | L: ");
  Serial.print((int)digitalRead(Pin::infraL));
  Serial.print(" | R: ");
  Serial.print((int)digitalRead(Pin::infraR));
  Serial.println();
  delay(500);
}
