int RED = A2;
int YELLOW = A3;
int GREEN = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED,LOW);
  delay(500);
  digitalWrite(YELLOW,LOW);
  delay(500);
  digitalWrite(GREEN,LOW);
  delay(500);
  digitalWrite(RED, HIGH);
  delay(500);
  digitalWrite(YELLOW, HIGH);
  delay(500);
  digitalWrite(GREEN, HIGH);
  delay(500);
}
