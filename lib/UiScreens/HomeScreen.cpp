
#include "Arduino.h"
#include "HomeScreen.h"

#include "Adafruit_GFX.h"
#include "Adafruit_HX8357.h"

//COMPASS DEFINITIONS
#define CIRCLE_RADIUS  123
#define CIRCLE_RADIUS_OUTER 135
#define CENTER_X  240
#define CENTER_Y 160

#define TRIANGLE_WIDTH 5



HomeScreen::HomeScreen(Adafruit_HX8357 *tft)
{
  _tft = tft;
  _heading = 90;
}

void HomeScreen::init() {


  /*
  * Ship with Circle
  */

  //Circle
  this->_tft->drawCircle(CENTER_X, CENTER_Y, CIRCLE_RADIUS-3, HX8357_WHITE);
  //Indicators
  this->updateIndicators(this->_heading);

}

void HomeScreen::updateCompass(uint16_t heading) {

  this->updateIndicators(heading);

  //Update heading
  this->_heading = heading;

}

void HomeScreen::updateIndicators(uint16_t heading) {
  //NORTH
  //Remove old north indicator
  float x0 = this->calculateX(this->_heading-TRIANGLE_WIDTH, CIRCLE_RADIUS);
  float y0 = this->calculateY(this->_heading-TRIANGLE_WIDTH, CIRCLE_RADIUS);
  float x1 = this->calculateX(this->_heading+TRIANGLE_WIDTH, CIRCLE_RADIUS);
  float y1 = this->calculateY(this->_heading+TRIANGLE_WIDTH, CIRCLE_RADIUS);
  float x2 = this->calculateX(this->_heading, CIRCLE_RADIUS_OUTER);
  float y2 = this->calculateY(this->_heading, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_BLACK);
  //Draw new north indicator
  x0 = this->calculateX(heading-TRIANGLE_WIDTH, CIRCLE_RADIUS);
  y0 = this->calculateY(heading-TRIANGLE_WIDTH, CIRCLE_RADIUS);
  x1 = this->calculateX(heading+TRIANGLE_WIDTH, CIRCLE_RADIUS);
  y1 = this->calculateY(heading+TRIANGLE_WIDTH, CIRCLE_RADIUS);
  x2 = this->calculateX(heading, CIRCLE_RADIUS_OUTER);
  y2 = this->calculateY(heading, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_RED);

  //SOUTH
  //Remove old south indicator
  x0 = this->calculateX(this->_heading-TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  y0 = this->calculateY(this->_heading-TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  x1 = this->calculateX(this->_heading+TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  y1 = this->calculateY(this->_heading+TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  x2 = this->calculateX(this->_heading+180, CIRCLE_RADIUS_OUTER);
  y2 = this->calculateY(this->_heading+180, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_BLACK);
  //Draw new south indicator
  x0 = this->calculateX(heading-TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  y0 = this->calculateY(heading-TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  x1 = this->calculateX(heading+TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  y1 = this->calculateY(heading+TRIANGLE_WIDTH+180, CIRCLE_RADIUS);
  x2 = this->calculateX(heading+180, CIRCLE_RADIUS_OUTER);
  y2 = this->calculateY(heading+180, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_WHITE);

  //WEST
  //Remove old west indicator
  x0 = this->calculateX(this->_heading-TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  y0 = this->calculateY(this->_heading-TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  x1 = this->calculateX(this->_heading+TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  y1 = this->calculateY(this->_heading+TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  x2 = this->calculateX(this->_heading+90, CIRCLE_RADIUS_OUTER);
  y2 = this->calculateY(this->_heading+90, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_BLACK);
  //Draw new west indicator
  x0 = this->calculateX(heading-TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  y0 = this->calculateY(heading-TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  x1 = this->calculateX(heading+TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  y1 = this->calculateY(heading+TRIANGLE_WIDTH+90, CIRCLE_RADIUS);
  x2 = this->calculateX(heading+90, CIRCLE_RADIUS_OUTER);
  y2 = this->calculateY(heading+90, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_WHITE);

  //EAST
  //Remove old east indicator
  x0 = this->calculateX(this->_heading-TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  y0 = this->calculateY(this->_heading-TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  x1 = this->calculateX(this->_heading+TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  y1 = this->calculateY(this->_heading+TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  x2 = this->calculateX(this->_heading+270, CIRCLE_RADIUS_OUTER);
  y2 = this->calculateY(this->_heading+270, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_BLACK);
  //Draw new east indicator
  x0 = this->calculateX(heading-TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  y0 = this->calculateY(heading-TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  x1 = this->calculateX(heading+TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  y1 = this->calculateY(heading+TRIANGLE_WIDTH+270, CIRCLE_RADIUS);
  x2 = this->calculateX(heading+270, CIRCLE_RADIUS_OUTER);
  y2 = this->calculateY(heading+270, CIRCLE_RADIUS_OUTER);
  this->_tft->fillTriangle(x0, y0, x1, y1, x2, y2, HX8357_WHITE);



}

float HomeScreen::calculateX(uint16_t heading, uint16_t circleRadius) {
  float x = CENTER_X + circleRadius * cos(heading*DEG_TO_RAD);

  return x;
}

float HomeScreen::calculateY(uint16_t heading, uint16_t circleRadius) {
  float y = abs(-CENTER_Y + circleRadius * sin(heading*DEG_TO_RAD));

  return y;
}
