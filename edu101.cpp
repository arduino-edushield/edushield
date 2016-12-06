/*
 * library for ATtiny2313 display
*/  

#include <Arduino.h>
#include <Wire.h>
#include "EDU101.h"

EDU101::EDU101()
{
  Wire.begin();
}

const uint8_t NUMBER_FONT[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111, // 9
  0b01110111, // A
  0b01111100, // B
  0b00111001, // C
  0b01011110, // D
  0b01111001, // E
  0b01110001  // F
}; 

  
// PUBLIC FUNCTIONS
void EDU101::set4(uint8_t a,uint8_t b,uint8_t c,uint8_t d) {
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x00);
  Wire.write(a);
  Wire.endTransmission();
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x01);
  Wire.write(b);
  Wire.endTransmission();
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x02);
  Wire.write(c);
  Wire.endTransmission();
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x03);
  Wire.write(d);
  Wire.endTransmission();
}

void EDU101::set(uint8_t a,uint8_t pos) {
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write(pos);
  Wire.write(a);
  Wire.endTransmission();
}


void EDU101::num4(uint8_t a,uint8_t b,uint8_t c,uint8_t d) {
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x00);
  Wire.write(NUMBER_FONT[a]);
  Wire.endTransmission();
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x01);
  Wire.write(NUMBER_FONT[b]);
  Wire.endTransmission();
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x02);
  Wire.write(NUMBER_FONT[c]);
  Wire.endTransmission();
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x03);
  Wire.write(NUMBER_FONT[d]);
  Wire.endTransmission();
}

void EDU101::num(uint8_t a,uint8_t pos) {
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write(pos);
  Wire.write(NUMBER_FONT[a]);
  Wire.endTransmission();
}



void EDU101::number(unsigned int n) {
  unsigned int d;
  if (n>9999) {EDU101::set4(0x80,0x80,0x80,0x80); return;}

  d = n / 1000;
  n = n % 1000;
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x00);
  Wire.write(NUMBER_FONT[d]);
  Wire.endTransmission();

  d = n / 100;
  n = n % 100;

  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x01);
  Wire.write(NUMBER_FONT[d]);
  Wire.endTransmission();

  d = n / 10;
  n = n % 10;

  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x02);
  Wire.write(NUMBER_FONT[d]);
  Wire.endTransmission();
  Wire.beginTransmission(DISPLAY_CTRL_ID);
  Wire.write((uint8_t)0x03);
  Wire.write(NUMBER_FONT[n]);
  Wire.endTransmission();
}


// PRIVATE FUNCTIONS

EDU101 Display = EDU101(); // create an instance for the user
