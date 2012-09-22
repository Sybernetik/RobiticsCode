/* 
 * Patterns for the Adafruit LED Pixels
 * by Syed Sakib
 * Version 1.0
 * 9/22/2012
 */

#include "SPI.h"
#include "Adafruit_WS2801.h"

int dataPin = 2; // Yellow wire.
int clockPin = 3; // Green wire.
const int numPixels = 10; // Number of LED pixels.
const uint32_t white = Color(255, 255, 255);
const uint32_t off = Color(0, 0, 0);

// First parameter is the number of pixels. (Pixel = 1 whole LED, not RGB)
Adafruit_WS2801 strip = Adafruit_WS2801(numPixels, dataPin, clockPin);

void setup() {
  strip.begin();
  strip.show(); // This updates the LED and shows the colors. They all start as 'off'.
}

void loop() { 
  /* 
   * This is the value that determines pattern behavior. 
   * Should replace '0' and retrieve data from pin on other Arduino.
   */
  int pinValue = 0;
  
  switch(pinValue) {
    case 0: // Forward pattern?
      patternForward();
      break;
    case 1: // Backward pattern?
      patternBackward();
      break;
    case 2: // Left turn pattern?
      patternLeft();
      break;
    case 3: // Right turn pattern?
      patternRight();
      break;
    case 4: // Pick up ball pattern?
      // Code
      break;
    case 5: // Drop ball pattern?
      // Code
      break;
    default: // Stationary pattern should go here.
      // Code
      break;
  } 
}

/***********************
 * Basic LED Functions *
 ***********************/
/* ~Useful Information~
 * strip.setPixelColor(int i, Color c) -- i = index of LED, c = Color object as RGB
 * It updates the designated LED pixel with a color in memory. Does not show.
 * 
 * strip.show()
 * Shows the color stored in the pixel. Use to actually update the colors physically.
 *
 * delay(int m) -- m = Number of milliseconds. (1000 milliseconds = 1 second)
 * Adds a delay to the program. Use to keep colors from changing for some time.
 *
 * The index at '0' and '(numPixels - 1)' is the back of the LEDs. Daisy chain should hang from front of robot.
 * Wiring -- Red is 5V. Blue is Ground (GND). Yellow is Data (Digital pin). Green is Clock (Digital pin).
 */

// Forward sweeps. 
void patternForward() {
 for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(index, white);
   strip.setPixelColor((numPixels - 1) - index, white);
   strip.show();
   delay(100);
 }
 
 for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(index, off);
   strip.setPixelColor((numPixels - 1) - index, off);
   strip.show();
   delay(75);
 }
 
 for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(index, white);
   strip.setPixelColor((numPixels - 1) - index, white);
   strip.show();
   delay(25);
   strip.setPixelColor(index, off);
   strip.setPixelColor((numPixels - 1) - index, off);
   strip.show();
   delay(25);
 }
}

// Backward sweeps.
void patternBackward() {
  for(int index = (numPixels / 2) - 1; index >= 0; index--) {
   strip.setPixelColor(index, white);
   strip.setPixelColor((numPixels - 1) - index, white);
   strip.show();
   delay(100);
 }
 
 for(int index = (numPixels / 2) - 1; index >= 0; index--) {
   strip.setPixelColor(index, off);
   strip.setPixelColor((numPixels - 1) - index, off);
   strip.show();
   delay(75);
 }
 
 for(int index = (numPixels / 2) - 1; index >= 0; index--) {
   strip.setPixelColor(index, white);
   strip.setPixelColor((numPixels - 1) - index, white);
   strip.show();
   delay(25);
   strip.setPixelColor(index, off);
   strip.setPixelColor((numPixels - 1) - index, off);
   strip.show();
   delay(25);
 }
}

// Counter-Clockwise sweeps.
void patternLeft() {
  for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(((numPixels / 2) - 1) - index, white);
   strip.setPixelColor((numPixels - 1) - index, white);
   strip.show();
   delay(100);
 }
 
 for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(((numPixels / 2) - 1) - index, off);
   strip.setPixelColor((numPixels - 1) - index, off);
   strip.show();
   delay(75);
 }
 
 for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(((numPixels / 2) - 1) - index, white);
   strip.setPixelColor((numPixels - 1) - index, white);
   strip.show();
   delay(25);
   strip.setPixelColor(((numPixels / 2) - 1) - index, off);
   strip.setPixelColor((numPixels - 1) - index, off);
   strip.show();
   delay(25);
 }
}

// Clockwise sweeps. 
void patternRight() {
  for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(index, white);
   strip.setPixelColor((numPixels / 2) + index, white);
   strip.show();
   delay(100);
 }
 
 for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(index, off);
   strip.setPixelColor((numPixels / 2) + index, off);
   strip.show();
   delay(75);
 }
 
 for(int index = 0; index < (numPixels / 2); index++) {
   strip.setPixelColor(index, white);
   strip.setPixelColor((numPixels / 2) + index, white);
   strip.show();
   delay(25);
   strip.setPixelColor(index, off);
   strip.setPixelColor((numPixels / 2) + index, off);
   strip.show();
   delay(25);
 }
}
 
// Create a 24 bit color value from R,G,B. (Copied from example code. Absolutely helpful.)
uint32_t Color(byte r, byte g, byte b) {
 uint32_t c;
 c = r;
 c <<= 8;
 c |= g;
 c <<= 8;
 c |= b;
 return c;
}
