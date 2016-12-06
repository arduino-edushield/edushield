#include <edushield.h>


void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  
  Serial.println("BeginN...");
  Display.number(2313);
  Serial.println("EndN...");
  delay(1000);

  Display.num4(4,5,6,7);
  delay(1000);

  Display.num4(8,9,10,11);
  delay(1000);

  Display.num4(12,13,14,15);
  delay(1000);

  Serial.println("Begin...");
  Display.set4(0x80,0x80,0x80,0x80);
  Serial.println("End...");
  delay(1000);
  
  Serial.println("Begin2...");
  Display.set4(0x77,0x76,0x3f,0x1e);
  Serial.println("End2...");
  delay(1000);

  Serial.println("Begin2...");
  Display.set4(0x37,0x06,0x39,0x80);
  Serial.println("End2...");
  delay(1000);

}
