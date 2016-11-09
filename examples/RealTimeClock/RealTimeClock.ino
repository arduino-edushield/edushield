#include <Wire.h>

// http://datasheets.maximintegrated.com/en/ds/DS1307.pdf
#define DS1307_CTRL_ID 0x68 

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(DS1307_CTRL_ID);
  // sekundy na adrese 0x00
  Wire.write((uint8_t)0x00);
  // sekundy jsou ulozeny v 1 byte
  Wire.requestFrom(DS1307_CTRL_ID, 3);
  int s = Wire.read();
  int m = Wire.read();
  int h = Wire.read();
  Wire.endTransmission();
  Serial.print((h & 0b01110000) >> 4);
  Serial.print(h & 0b00001111);
  Serial.print(":");
  Serial.print((m & 0b01110000) >> 4);
  Serial.print(m & 0b00001111);
  Serial.print(":");
  Serial.print((s & 0b01110000) >> 4);
  Serial.println(s & 0b00001111);
  
  delay(1000);
}
