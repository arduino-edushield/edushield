/**
 *
 * EduShield LED Firmware version 3
 *
 * It works as I2C slave at address 0x27
 *
 * Use provided libraries and hardware folders
 *
 * Compile for ATtiny2313 @ 1MHz
 *
 * Use Arduino as ISP
 *
 * 
 */

#include <TinyWireS.h>

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

uint8_t display[4] = {0x79,0x5e,0x1c,0x6d}; //0x9e


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
  TinyWireS.onRequest(requestEvent);
  
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
