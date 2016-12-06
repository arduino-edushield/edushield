#include <Wire.h>

#include <edushield.h>

int RED = A2;
int YELLOW = A3;
int GREEN = 13;

int R = 6;
int G = 5;
int B = 9;

void setup() {
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, HIGH);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  digitalWrite(R, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
}

#define TRON    digitalWrite(RED,LOW);
#define TROFF   digitalWrite(RED,HIGH);
#define TYON    digitalWrite(YELLOW,LOW);
#define TYOFF   digitalWrite(YELLOW,HIGH);
#define TGON    digitalWrite(GREEN,LOW);
#define TGOFF   digitalWrite(GREEN,HIGH);

#define RON    digitalWrite(R,LOW);
#define ROFF   digitalWrite(R,HIGH);
#define GON    digitalWrite(G,LOW);
#define GOFF   digitalWrite(G,HIGH);
#define BON    digitalWrite(B,LOW);
#define BOFF   digitalWrite(B,HIGH);


void loop() {
  
  Serial.println("BeginN...");
  Display.number(2313);
  Serial.println("EndN...");
  
  TRON
  
  for (int i=255;i>0;i--) {
    analogWrite(R,i);  
    delay(5);
  }

  Display.num4(4,5,6,7);

  TYON

  for (int i=255;i>0;i--) {
    analogWrite(G,i);  
    delay(5);
  }

  Display.num4(8,9,10,11);

  TGON
  TROFF
  TYOFF
  
  for (int i=255;i>0;i--) {
    analogWrite(B,i);  
    delay(5);
  }


  Display.num4(12,13,14,15);

  
  for (int i=0;i<255;i++) {
    analogWrite(R,i);  
    delay(5);
  }

  

  Serial.println("Begin...");
  Display.set4(0x80,0x80,0x80,0x80);
  Serial.println("End...");

  TYON
  TGOFF

  for (int i=0;i<255;i++) {
    analogWrite(G,i);  
    delay(5);
  }
  
  Serial.println("Begin2...");
  Display.set4(0x77,0x76,0x3f,0x1e);
  Serial.println("End2...");

  TRON
  TYOFF

  for (int i=0;i<255;i++) {
    analogWrite(B,i);  
    delay(5);
  }

  Serial.println("Begin2...");
  Display.set4(0x37,0x06,0x39,0x80);
  Serial.println("End2...");

  delay(1000);
  

}
