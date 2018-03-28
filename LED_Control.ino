/*
Resource:
https://maker.pro/projects/arduino/arduino-led-matrix
https://create.arduino.cc/projecthub/SAnwandter1/programming-8x8-led-matrix-23475a
http://www.instructables.com/id/LED-Matrix-with-Arduino/
*/
#include "LedControl.h"
#include <binary.h>

/*  
 * Params - LedControl(dataPin,clockPin,csPin,numDevices)
 * int dataPin    The pin on the Arduino where data gets shifted out
 * int clockPin   The pin for the clock
 * int csPin      The pin for selecting the device when data is to be sent
 * int numDevices The maximum number of devices that can be controlled
 *
 * addr is the address of the LED display. Address starts at 0 and goes up. 
 * Repeat all instructions for lc2 in order to have both light up. lc2 address = 1
*/

LedControl lc1=LedControl(1, 2, 3, 1); 
int lc1_addr = 0;

void setup() {
  //wake up the MAX72XX (LED array) from power-saving mode 
  lc1.shutdown(lc1_addr,false);
  //set a medium brightness for the Leds
  lc1.setIntensity(lc1_addr,8);
  lc1.clearDisplay(lc1_addr);
}

/* 
 * Set the status of a single Led.
 * Params - setLed(int addr, int row, int col, boolean state)
 * addr  address of the display 
 * row   the row of the Led (0..7)
 * col   the column of the Led (0..7)
 * state If true the led is switched on, if false it is switched off
 * Alternatively: setRow(addr,row,value in binary) e.g. lc.setRow(0,2,B10110000). setColumn also exists, though setRow is the fastest method. 
 */
void loop() {
  breathing_loop();
}

void breathing_loop() {
  for (int i = 0; i<=15; i++) {
    delay(1000);
    lc1.setIntensity(lc1_addr,i);
    lc1.setRow(lc1_addr,0,B11111111);
    lc1.setRow(lc1_addr,1,B11111111);
    lc1.setRow(lc1_addr,2,B11111111);
    lc1.setRow(lc1_addr,3,B11111111);
    lc1.setRow(lc1_addr,4,B11111111);
    lc1.setRow(lc1_addr,5,B11111111);
    lc1.setRow(lc1_addr,6,B11111111);
    lc1.setRow(lc1_addr,7,B11111111);
  }
  delay(1500);
  for (int e = 15; e >= 0; e--) {
    delay(1000);
    lc1.setIntensity(lc1_addr,e);
    lc1.setRow(lc1_addr,0,B11111111);
    lc1.setRow(lc1_addr,1,B11111111);
    lc1.setRow(lc1_addr,2,B11111111);
    lc1.setRow(lc1_addr,3,B11111111);
    lc1.setRow(lc1_addr,4,B11111111);
    lc1.setRow(lc1_addr,5,B11111111);
    lc1.setRow(lc1_addr,6,B11111111);
    lc1.setRow(lc1_addr,7,B11111111);
  }
  delay(1500);
}
