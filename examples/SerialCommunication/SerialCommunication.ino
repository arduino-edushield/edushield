int GREEN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN,OUTPUT);
  digitalWrite(GREEN, LOW);
  Serial.println("Send 0 or 1 to control LED");
}

void loop() {
    if (Serial.available() > 0) {
      char led = Serial.read();

      switch(led) {
        case '0':
          digitalWrite(GREEN, LOW);
          break;
        case '1':
          digitalWrite(GREEN, HIGH);       
          break;
      }
    }
}