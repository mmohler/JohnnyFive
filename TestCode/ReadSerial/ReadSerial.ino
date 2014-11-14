const int ledPin = 8;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  //if (Serial.available())  {
     //light((int)Serial.read() - 0);
     //light(1);
  //}
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  delay(500);
  
}

void light(int n){
  for (int i = 0; i < n; i++)  {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
