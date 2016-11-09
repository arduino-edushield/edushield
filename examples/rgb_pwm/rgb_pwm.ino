int RED = 6;
int GREEN = 5;
int BLUE = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

void loop() {
  for (int i=255;i>0;i--) {
    analogWrite(RED,i);  
    delay(10);
  }
  
  for (int i=255;i>0;i--) {
    analogWrite(BLUE,i);  
    delay(10);
  }
  for (int i=255;i>0;i--) {
    analogWrite(GREEN,i);  
    delay(10);
  }

  for (int i=0;i<255;i++) {
    analogWrite(RED,i);  
    delay(10);
  }

  for (int i=0;i<255;i++) {
    analogWrite(BLUE,i);  
    delay(10);
  }
  for (int i=0;i<255;i++) {
    analogWrite(GREEN,i);  
    delay(10);
  }


}
