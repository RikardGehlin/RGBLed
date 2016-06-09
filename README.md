A small library to control RGB leds on an Arduino

  void setColors(int redColor, int greenColor, int blueColor); // A function to change the stored values for colors. NOTE, does not actually change the color of the led. See turnOFF()
  void turnOn(); // Lights the led with the stored color values. Also contains logic for common anodes/cathodes;
  void turnOff(); // Sets the color to black and then calls turnOn();
  void fadeTo(int newRed, int newGreen, int newBlue, int duration); //Fades the color between the stored colors and these new ones over a given amount of time
