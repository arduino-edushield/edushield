int RED = A2;
int YELLOW = A3;
int GREEN = 13;

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
/* 
  The formula is taken from https://en.wikipedia.org/wiki/Thermistor#B_or_.CE.B2_parameter_equation
  Magic "B" is described in datasheet: http://www.meritekusa.com/web/upload/201310241633572r=SY3v.pdf
*/
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
  Serial.println(temp);
  
  
  delay(500);
}
