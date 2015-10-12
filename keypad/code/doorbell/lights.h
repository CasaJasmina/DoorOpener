
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int lightsAddress[] = {0, 5, 6, 1, 4, 7, 2, 3, 8};


void resetPixels() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(30, 30, 30));
    pixels.show();
    delay(2);
  }
}

void turnOnPixel(int pixel) {
  for (int i = 0; i < 255; i++) {
    pixels.setPixelColor(lightsAddress[pixel], pixels.Color(i, i, i));
    pixels.show();
    delayMicroseconds(10);
  }
}
void turnOffPixel(int pixel) {
  for (int i = 255; i > 50; i--) {
    pixels.setPixelColor(lightsAddress[pixel], pixels.Color(i, i, i));
    pixels.show();
    delayMicroseconds(20);
  }
}

void showError(){
    for (int n=0;n<3;n++){
         for (int i = 0; i <150; i++) {
            for(int j=0; j<NUMPIXELS;j++){
                pixels.setPixelColor(j, pixels.Color(i, 0, 0));
            }
            delay(1);
            pixels.show();
        }
        for (int i = 255; i >0; i--) {
            for(int j=0; j<NUMPIXELS;j++){
                pixels.setPixelColor(j, pixels.Color(i, 0, 0));
            }
            delay(1);
            pixels.show();
        }
    }
}

void showGood(){
    for (int n=0;n<3;n++){
         for (int i = 0; i <150; i++) {
            for(int j=0; j<NUMPIXELS;j++){
                pixels.setPixelColor(j, pixels.Color(0, i, 0));
            }
            delay(1);
            pixels.show();
        }
        for (int i = 255; i >0; i--) {
            for(int j=0; j<NUMPIXELS;j++){
                pixels.setPixelColor(j, pixels.Color(0, i, 0));
            }
            delay(1);
            pixels.show();
        }
    }
}
