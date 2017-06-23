int RED = A2;
int YELLOW = A3;
int GREEN = 13;
int BUTTON = 2;

#include <avr/sleep.h>          // library for sleep
#include <avr/power.h>          // library for power control

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
  showLights();
}

// Put the Arduino to deep sleep. Only an interrupt can wake it up.
void sleep()
{ 

  // Set sleep to full power down.  Only external interrupts or
  // the watchdog timer can wake the CPU!
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
 
  // Turn off the ADC while asleep.
  power_adc_disable();
 
  // Enable sleep and enter sleep mode.
  sleep_mode();

  // CPU is now asleep and program execution completely halts!
  // Once awake, execution will resume at this point if the
  // watchdog is configured for resume rather than restart
 
  // When awake, disable sleep mode
  sleep_disable();

  // put everything on again
  power_all_enable();
 
}


void loop() {
  showLights();
  sleep();
}
