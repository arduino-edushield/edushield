#include <TinyWireS.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

#define PIN_D0  ( 0)
#define PIN_D1  ( 1)
#define PIN_A1  ( 2)
#define PIN_A0  ( 3)
#define PIN_D2  ( 4)
#define PIN_D3  ( 5)
#define PIN_D4  ( 6)
#define PIN_D5  ( 7)
#define PIN_D6  ( 8)
#define PIN_B0  ( 9)
#define PIN_B1  (10)
#define PIN_B2  (11)
#define PIN_B3  (12)
#define PIN_B4  (13)
#define PIN_B5  (14)
#define PIN_B6  (15)
#define PIN_B7  (16)
#define PIN_A2  (17)

#define POS1 7
#define POS2 11
#define POS3 12
#define POS4 13

#define SEGA 10
#define SEGB 8
#define SEGC 5
#define SEGD 3
#define SEGE 2
#define SEGF 9
#define SEGG 6
#define SEGH 4

#define WAIT 2

uint8_t display[4] = {0x77,0x76,0x3f,0x3f}; //0x9e

// global buffer to store data sent from the master.
uint8_t master_data[16];
// global variable to number of bytes sent from the master.
uint8_t master_bytes;

// Gets called when the ATtiny receives an i2c write slave request
void receiveEvent(uint8_t num_bytes)
{
  uint8_t i;
  
  // save the number of bytes sent from the master
  //if (num_bytes!=2) return;

  // store the data from the master into the data buffer
  i = TinyWireS.receive();
  if (i==0xff) return;
  display[i] = TinyWireS.receive();

}

// Gets called when the ATtiny receives an i2c read slave request
void requestEvent()
{
  uint8_t i;
  
  // send the data buffer back to the master
  for (i = 0; i < master_bytes; i++)
    TinyWireS.send(master_data[i]);

  // corrupt the byte values in the data buffer
  // so that subsequent call won't match
  for (i = 0; i < master_bytes; i++)
    master_data[i] += 0x5a;

  // corrupt length of the request, but dont' make it zero
  
  // if the usiTwiSlave.c is working fine, then this number is completely irrelevant
  // because the requestEvent() callback will not be called again until
  // after the next receiveEvent() callback, so the master_data and
  // master_bytes variables will be set by that call.

  // If the usiTwiSlave.c has the issue of calling the requestFrom() callback
  // for each byte sent, the buffer will accumulate by this amount *for each byte
  // in the original request*.
  // 
  // Making it zero will obscure the 1-byte send issue in the usiTwiSlave.c
  // that is being tested.
  // Making it small will allow a few requests to succeed before the tx buffer
  // overflows and the usiTwiSlave.c hangs on the "while ( tmphead == txTail );"
  // line
  master_bytes = 2; 
}


// the setup function runs once when you press reset or power the board
void setup() {

  
  // initialize digital pin 13 as an output.
  //DDRD |= 0xff;
  
  pinMode(POS1, OUTPUT);
  pinMode(POS2, OUTPUT);
  pinMode(POS3, OUTPUT);
  pinMode(POS4, OUTPUT);

  digitalWrite(POS1,LOW);
  digitalWrite(POS2,LOW);
  digitalWrite(POS3,LOW);
  digitalWrite(POS4,LOW);

  pinMode(SEGA, OUTPUT);
  pinMode(SEGB, OUTPUT);
  pinMode(SEGC, OUTPUT);
  pinMode(SEGD, OUTPUT);
  pinMode(SEGE, OUTPUT);
  pinMode(SEGF, OUTPUT);
  pinMode(SEGG, OUTPUT);
  pinMode(SEGH, OUTPUT);

  // initialize the TinyWireS and usiTwiSlave libraries
  TinyWireS.begin(0x27);      // init I2C Slave mode

  // register the onReceive() callback function
  TinyWireS.onReceive(receiveEvent);
  
  // register the onRequest() callback function
  //TinyWireS.onRequest(requestEvent);
  
}

void onePos(uint8_t seg) {
  digitalWrite(SEGA,!(seg&0x01));
  digitalWrite(SEGB,!((seg&0x02)>>1));
  digitalWrite(SEGC,!((seg&0x04)>>2));
  digitalWrite(SEGD,!((seg&0x08)>>3));
  digitalWrite(SEGE,!((seg&0x10)>>4));
  digitalWrite(SEGF,!((seg&0x20)>>5));
  digitalWrite(SEGG,!((seg&0x40)>>6));
  digitalWrite(SEGH,!((seg&0x80)>>7));
}

// the loop function runs over and over again forever
void refresh() {
  onePos(display[3]);
  digitalWrite(POS1,HIGH);
  tws_delay(WAIT);
  digitalWrite(POS1,LOW);
  onePos(display[2]);
  digitalWrite(POS2,HIGH);
  tws_delay(WAIT);
  digitalWrite(POS2,LOW);
  onePos(display[1]);
  digitalWrite(POS3,HIGH);
  tws_delay(WAIT);
  digitalWrite(POS3,LOW);
  onePos(display[0]);
  digitalWrite(POS4,HIGH);
  tws_delay(WAIT);
  digitalWrite(POS4,LOW);
}

// the loop function runs over and over again forever
void loop() {
  TinyWireS_stop_check();
  refresh();
}
