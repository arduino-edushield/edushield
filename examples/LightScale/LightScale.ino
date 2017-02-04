int RED = A2;
int YELLOW = A3;
int GREEN = 13;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, HIGH);  
}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);
  
  int scale = map(light, 200, 1000, 0, 2);
  //Serial.println(scale);
  
  if (scale==0) {
    digitalWrite(RED, HIGH);
  } else {
    digitalWrite(RED, LOW);
  }

  if (scale<1) {
    digitalWrite(YELLOW, HIGH);
  } else {
    digitalWrite(YELLOW, LOW);
  }

  if (scale<2) {
    digitalWrite(GREEN, HIGH);
  } else {
    digitalWrite(GREEN, LOW);
  }

  
  delay(200);
}