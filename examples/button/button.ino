int RED = 6;
int GREEN = 5;
int BLUE = 9;
int BUTTON = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int b = digitalRead(BUTTON);
  digitalWrite(RED,b);
  digitalWrite(GREEN,b);
  digitalWrite(BLUE,b);
}
