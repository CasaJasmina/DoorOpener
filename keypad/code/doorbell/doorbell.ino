#include <Wire.h>
#include <MPR121.h>

// You can have up to 4 on one i2c bus but one is enough for testing!

#include "touch.h"

// Keeps track of the last pins touched
// so we know when buttons are 'released'


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            9
#define NUMPIXELS      12

#define numElectrodes 12

#include "lights.h"
#include "code.h"

int keylength = 4;
int keypressed[4];

int dooropener = 13;

void setup() {
  Serial.begin(9600);
  pinMode (dooropener, OUTPUT);

  Wire.begin();

  if (!MPR121.begin(0x5A)) {
    Serial.println("error setting up MPR121");
    switch (MPR121.getError()) {
      case NO_ERROR:
        Serial.println("no error");
        break;
      case ADDRESS_UNKNOWN:
        Serial.println("incorrect address");
        break;
      case READBACK_FAIL:
        Serial.println("readback failure");
        break;
      case OVERCURRENT_FLAG:
        Serial.println("overcurrent on REXT pin");
        break;
      case OUT_OF_RANGE:
        Serial.println("electrode out of range");
        break;
      case NOT_INITED:
        Serial.println("not initialised");
        break;
      default:
        Serial.println("unknown error");
        break;
    }
    while (1);
  }




  // pin 4 is the MPR121 interrupt on the Bare Touch Board
  MPR121.setInterruptPin(4);

  // this is the touch threshold - setting it low makes it more like a proximity trigger
  // default value is 40 for touch
  MPR121.setTouchThreshold(10);

  // this is the release threshold - must ALWAYS be smaller than the touch threshold
  // default value is 20 for touch
  MPR121.setReleaseThreshold(8);

  // initial data update
  MPR121.updateTouchData();


  pixels.begin(); // This initializes the NeoPixel library.
  resetPixels();
}

void loop() {
  int newTouch = checkTouchReleased() + 1;
  if (newTouch != 0) {
    Serial.println(newTouch);
    turnOnPixel(newTouch - 1);
    turnOffPixel(newTouch - 1);


    for (int i = 0; i < 4; i++) {
      if (keypressed[i] == 0) {
        keypressed[i] = newTouch;
        if (i == keylength - 1) {
          //here I verify the combination
          Serial.println("verifico Combinazione");
          if (checkCombination()) {
            Serial.println("open the door");
            showGood();
            openTheDoor();

          } else {
            Serial.println("error");
            showError();
          }
          resetKeys();
          resetPixels();
        }
        break;
      }
    }

    if (keypressed)
      for (int i = 0; i < 4; i++) {
        Serial.print(keypressed[i]);
        Serial.print(" ");
      }
    Serial.println();
  }
}

boolean checkCombination() {
  for (int i = 0; i < keylength; i++) {
    if (keypressed[i] != combination[i]) {
      return (false);
    }
  }
  return (true);
}

boolean resetKeys() {
  for (int i = 0; i < keylength; i++) {
    keypressed[i] = 0;
  }
}

void openTheDoor() {
  digitalWrite(dooropener, HIGH);
  delay(1000);
  digitalWrite(dooropener, LOW);

}


