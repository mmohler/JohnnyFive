void setup() {
    pinMode(6, INPUT);      // sets the digital pin 7 as input
    Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(6));
}
