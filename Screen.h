#ifndef Screen_h
#define Screen_h

#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

class Screen
{
private:
  Adafruit_SSD1306 *screen;

public:
  ~Screen();
  void begin();
  void show(const char *str);
  void show(const char *str,uint8_t size);
  void show(const char *str,uint8_t size, uint8_t leftPadding, uint8_t topPadding);
  void showTwoLine(const char *title,const char *msg);
  void mainScreen(String datetime, String temperature, String humidity, String msg);
  
};

#endif
