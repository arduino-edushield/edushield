int RED = A2;
int YELLOW = A3;
int GREEN = 13;
int BUTTON = 2;

int currentState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP); 
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);

  pinMode(BUTTON, INPUT);
  // https://www.arduino.cc/en/Reference/AttachInterrupt
  attachInterrupt(digitalPinToInterrupt(BUTTON), newState, FALLING);

  showLights();
}



void showLights() {
  switch (currentState) {
    case 0: 
      digitalWrite(RED,HIGH);
      digitalWrite(YELLOW,LOW);
      digitalWrite(GREEN, LOW);
      break;
    case 1: 
      digitalWrite(RED,HIGH);
      digitalWrite(YELLOW,HIGH);
      digitalWrite(GREEN, LOW);
      break;
    case 2: 
      digitalWrite(RED,LOW);
      digitalWrite(YELLOW,LOW);
      digitalWrite(GREEN, HIGH);
      break;
    case 3: 
      digitalWrite(RED,LOW);
      digitalWrite(YELLOW,HIGH);
      digitalWrite(GREEN, LOW);
      break;
  }
}

void newState() {
  switch (currentState) {
    case 0:
      currentState = 1;
      break;
    case 1:
      currentState = 2;
      break;
    case 2:
      currentState = 3;
      break;
    case 3:
      currentState = 0;
      break;
  }
}

void loop() {
  showLights();
}
