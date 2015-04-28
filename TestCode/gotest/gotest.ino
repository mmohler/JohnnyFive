#include <PinMap.h>
int a,b;
void setup() {
  pinMode(Pin::mazeSizeA, INPUT_PULLUP);
  pinMode(Pin::mazeSizeB, INPUT_PULLUP);  
  pinMode(Pin::goBtn, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  a = (int)digitalRead(Pin::mazeSizeA);
  b = (int)digitalRead(Pin::mazeSizeB);
  Serial.print((int)digitalRead(Pin::goBtn));
  Serial.print(" | ");
  if (!a && b) {
    Serial.println("5x5");
  }
  if (a && b) {
    Serial.println("6x6");
  }
  if (a && !b) {
    Serial.println("7x7");
  }
  //Serial.print((int)digitalRead(Pin::mazeSizeA));
  //Serial.println((int)digitalRead(Pin::mazeSizeB));
  delay(100);
}
