int LED = 13;

void setup() {
  // Tento kod se vykona jen jednou
  pinMode(LED,OUTPUT);
}

void loop() {
  // Tento kod se vykonava stale dokola
  digitalWrite(LED,LOW);
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
}
