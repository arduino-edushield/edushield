int RED = A2;
int YELLOW = A3;
int GREEN = 13;

#include <edu101.h>

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, HIGH);  
}


#define RESISTOR_CONNECT_THERMISTOR  10000
/*Return:int8_t,Temperature that range from -40 to 125 degrees.  */
int8_t getTemperature()
{
  float temperature,resistance;
  int a;
  a = analogRead(A1);
  resistance   = (float)(1023-a)*RESISTOR_CONNECT_THERMISTOR/a; //Calculate the resistance of the thermistor
  int B = 3975;
  /*Calculate the temperature according to the following formula.*/
  temperature  = 1/(log(resistance/RESISTOR_CONNECT_THERMISTOR)/B+1/298.15)-273.15;
  return (int8_t)temperature;// the type convert from floating point to 8-bit integer
}

void loop() {
  int temp = getTemperature();
  displayTemperature(temp);
  Serial.println(temp);
  
  
  delay(500);
}

#define INDEX_NEGATIVE_SIGN 0x40
#define INDEX_BLANK 0x00

void displayTemperature(int8_t temperature)
{
  int8_t temp[4];
  if(temperature < 0)//if the temperature is below zero?
  {
  /*Yes, then the left-most bit will display "-".*/
    temp[0] = INDEX_NEGATIVE_SIGN;
    temperature = abs(temperature);
  }
  else if(temperature < 100)//if temperature >= 0 and temperature < 100?
  {
  /*Yes, then the left-most bit will display nothing.*/
    temp[0] = INDEX_BLANK;
  }
  else //if temperature > 100?
  {
  /*Yes, then the left-most bit will normally display.*/
    temp[0] = temperature/100;
  }
  temperature %= 100;
  temp[1] = temperature / 10;//index of second bit from left
  temp[2] = temperature % 10;//index of the third bit from left
  temp[3] = 12;           //index of 'C' for celsius degree symbol.
  Display.num(temp[1],0);
  Display.num(temp[2],1);
  Display.set(0x63,2);
  Display.num(12,3);
}

