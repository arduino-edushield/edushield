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
  // put your main code here, to run repeatedly:
  digitalWrite(RED,LOW);
  delay(500);
  digitalWrite(GREEN,LOW);
  delay(500);
  digitalWrite(BLUE,LOW);
  delay(500);
  digitalWrite(RED, HIGH);
  delay(500);
  digitalWrite(GREEN, HIGH);
  delay(500);
  digitalWrite(BLUE, HIGH);
  delay(500);
}
