
#ifndef Compass_h
#define Compass_h

#include "Arduino.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>


class Compass
{
  public:
    Compass(Adafruit_LSM303_Mag_Unified &mag);
    void readCompass();
  private:
    Adafruit_LSM303_Mag_Unified *_mag;
};

#endif
