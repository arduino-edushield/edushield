int RED = A2;
int YELLOW = A3;
int GREEN = 13;
int BUTTON = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP); 
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
}

int stav = 0;

void showLights() {
  switch (stav) {
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
  switch (stav) {
    case 0:
      stav = 1;
      break;
    case 1:
      stav = 2;
      break;
    case 2:
      stav = 3;
      break;
    case 3:
      stav = 0;
      break;
  }
}

void loop() {
  showLights();
  if (digitalRead(BUTTON) == LOW) {
    newState();  

// Zkuste si tyto 3 radky odstranit
    while (digitalRead(BUTTON) == LOW) {  
      ;
    }


  }
}
