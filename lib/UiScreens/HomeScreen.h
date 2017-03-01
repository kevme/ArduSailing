
#ifndef HomeScreen_h
#define HomeScreen_h

#include "Arduino.h"
#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"



class HomeScreen
{
  public:
    HomeScreen(Adafruit_HX8357 *tft);
    void init();
    void updateCompass(uint16_t heading);
  private:
    Adafruit_HX8357 *_tft;
    uint16_t _heading;
    float calculateX(uint16_t heading, uint16_t circleRadius);
    float calculateY(uint16_t heading, uint16_t circleRadius);
    void updateIndicators(uint16_t heading);
};

#endif
