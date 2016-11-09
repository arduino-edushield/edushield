int RED = A2;
int YELLOW = A3;
int GREEN = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED,HIGH);
  delay(1500);
  digitalWrite(YELLOW,HIGH);
  delay(1000);
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW,LOW);
  digitalWrite(GREEN,HIGH);
  delay(1500);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW,HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);
}
