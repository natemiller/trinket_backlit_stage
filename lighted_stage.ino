#include "Adafruit_WS2801.h"
//#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

#define NUMPIXELS 5 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    0  
#define CLOCKPIN   1

const int buttonPin = 2;
unsigned long startTime;
int j = 0;

Adafruit_WS2801 strip = Adafruit_WS2801(NUMPIXELS, DATAPIN, CLOCKPIN);

 /* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos) 
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}


void rainbow(long wait) {
  int i;
    if((millis() - startTime) >= wait) {
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 255));
    }  
    strip.show();   // write all the pixels out
    if(j < 256) {
    j++;
    }else{
      j=0;
    }
    startTime = millis();
    }
}

 uint32_t RED = Color(255, 0, 0);
 uint32_t GREEN = Color(0, 255, 0);
 uint32_t  BLUE = Color(0, 0, 255);
 uint32_t  YELLOW = Color(255,255, 0);
 uint32_t  TURQUOISE = Color(0, 255, 255);
 uint32_t  PINK = Color(255, 0, 255);
 uint32_t  LIGHTYELLOW = Color(255, 255, 128);
 uint32_t  LIGHTBLUE = Color(128, 255, 255);
 uint32_t  ROSE = Color(255, 128, 255);
 uint32_t  ORANGE = Color(255, 128, 0);
 uint32_t  LIME = Color(128, 255, 0);
 uint32_t  VIOLET = Color(128, 0, 255);
 uint32_t  DIRTYYELLOW = Color(128, 128, 0);
 uint32_t  PLUM = Color(128, 0, 128);
 uint32_t  TEAL = Color(0, 128, 128);
 uint32_t  WHITE = Color(255, 255, 255);

 uint32_t Colours [] = {RED,GREEN,BLUE,YELLOW,TURQUOISE,PINK,LIGHTYELLOW,LIGHTBLUE,ROSE,ORANGE,LIME,VIOLET,DIRTYYELLOW,PLUM,TEAL,WHITE};

 int buttonState = 0;
 int buttonCounter = 15;
 int lastButtonState = 0;

 
void setup() {

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  pinMode(buttonPin, INPUT);
  
  strip.begin(); // Initialize pins for output
  
  for (int k = 0; k < 6; k++) {
    strip.setPixelColor(k, Colours[buttonCounter]);
    strip.show();
    }

    startTime = millis();
  }

void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState != lastButtonState) {
    if(buttonState == HIGH) {
      if(buttonCounter <= 16) {
      buttonCounter++;
      } if(buttonCounter > 16) {
        buttonCounter = 0;
      } 
    }
    delay(50);
  }
  lastButtonState = buttonState;

    
    if(buttonCounter < 16) {
      for(int k = 0; k < 6; k++) {
        strip.setPixelColor(k, Colours[buttonCounter]);
        strip.show();
      }
    }
    if(buttonCounter == 16) {
          rainbow(100);
        }
      }





