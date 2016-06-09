/*
  RGBLed.h - Library for controling RGBLeds.
  Created by Rikard Gehlin, June 09, 2016.
  Released into the public domain.
*/
#ifndef RGBLed_h
#define RGBLed_h
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

#include "Arduino.h"
class RGBLed
{
  private:
    int redPin, greenPin, bluePin;
    int redColor, greenColor, blueColor;
  
  public:
    RGBLed(int redPin, int greenPin, int bluePin);
    void setColors(int redColor, int greenColor, int blueColor);
    void turnOn();
    void turnOff();
    void fadeTo(int newRed, int newGreen, int newBlue, int duration);
};
#endif