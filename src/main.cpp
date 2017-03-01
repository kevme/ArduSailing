
#include "Arduino.h"

#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"

#include "HomeScreen.h"

/*
*Setup the TFT display and touchscreen
*/
// These are 'flexible' lines that can be changed
#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 8 // RST can be set to -1 if you tie it to Arduino's reset
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_HX8357 tft = Adafruit_HX8357(TFT_CS, TFT_DC, TFT_RST);
HomeScreen homeScreen(&tft);


void setup() {

  Serial.begin(9600);
  Serial.println("Starting Sailing Computer.");





  tft.begin(HX8357D);
  tft.setRotation(1);
  tft.fillScreen(HX8357_BLACK);

  /*tft.setCursor(10, 50);



  tft.setTextColor(HX8357_WHITE);
  tft.setTextSize(2);
  tft.println("Starting up Sailing Computer");
  */


  homeScreen.init();

}


void loop() {

  for (uint16_t i = 90; i < 450; i += 2) {
    homeScreen.updateCompass(i);
    delay(100);
  }


}
