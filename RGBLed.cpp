/*
  RGBLed.cpp - Library for controling RGBLeds.
  Created by Rikard Gehlin, June 09, 2016.
  Released into the public domain.
*/
#include "Arduino.h"
#include "RGBLed.h"

RGBLed::RGBLed(int redPin, int greenPin, int bluePin)
{
  this->redPin = redPin;
  this->greenPin = greenPin;
  this->bluePin = bluePin;
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void RGBLed::setColors (int redColor, int greenColor, int blueColor) {
  this->redColor = redColor;
  this->greenColor = greenColor;
  this->blueColor = blueColor;
}

void RGBLed::turnOn () {
  #ifdef COMMON_ANODE
    analogWrite(this->redPin, 255 - this->redColor);
    analogWrite(this->greenPin, 255 - this->greenColor);
    analogWrite(this->bluePin, 255 - this->blueColor);
  #else
    analogWrite(this->redPin, this->redColor);
    analogWrite(this->greenPin, this->greenColor);
    analogWrite(this->bluePin, this->blueColor);
  #endif
}

void RGBLed::turnOff () {
  this->setColors(0, 0, 0);
  this->turnOn();
}

void RGBLed::fadeTo(int newRed, int newGreen, int newBlue, int duration){
  unsigned long currentTime = 0; // Generally, you should use "unsigned long" for variables that hold time

  int oldRed = this->redColor;
  int oldGreen = this->greenColor;
  int oldBlue = this->blueColor;
 
  int fadedRed = 0;
  int fadedGreen = 0;
  int fadedBlue = 0;
     
  while (currentTime <= duration){    
    float stepSize = (float)currentTime / (float)duration;
    
    fadedRed = oldRed + (newRed - oldRed) * stepSize;
    fadedGreen = oldGreen + (newGreen - oldGreen) * stepSize;
    fadedBlue = oldBlue + (newBlue - oldBlue) * stepSize;
    
    this->setColors(fadedRed, fadedGreen, fadedBlue);
    this->turnOn();

    currentTime++;
  }
}