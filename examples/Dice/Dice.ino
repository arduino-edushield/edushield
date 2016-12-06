#include <Wire.h>

#include <edushield.h>


int BUTTON = 2;

void setup() {
  pinMode(BUTTON,INPUT_PULLUP);
  //delay(1000);
  Display.set(0,0);
  Display.set(0,1);
  Display.set(0,2);
}

int num = 1;

void loop() {
  Display.num(num,3);

  int b = digitalRead(BUTTON);
  
  if (!b) {
    num++;
    if (num==7) num=1;
  } 
    delay(10);


}
