#include "Screen.h"

Screen::~Screen()
{
  delete this->screen;
}

void Screen::begin()
{
  Adafruit_SSD1306 *dis = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  this->screen = dis;

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!screen->begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    while (true) {
      // Don't proceed, loop forever
      delay(100000);
    }
  }
  screen->display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  screen->clearDisplay();
}

void Screen::show(const char *str)
{
  show(str, 1);
}

void Screen::show(const char *str, uint8_t size) {
  show(str, size, 0, 26);
}

void Screen::show(const char *str, uint8_t size, uint8_t leftPadding, uint8_t topPadding) {
  screen->clearDisplay();
  screen->setTextSize(size); // Normal 1:1 pixel scale
  screen->setTextColor(SSD1306_WHITE);   // Draw white text
  screen->setCursor(leftPadding, topPadding);       // Start at top-left corner
  screen->println(F(str));

  screen->display();
}

void Screen::showTwoLine(const char *title, const char *msg) {
  screen->clearDisplay();
  screen->setTextSize(2);
  screen->setTextColor(SSD1306_WHITE);   // Draw white text
  screen->setCursor(0, 0);       // Start at top-left corner
  screen->println(F(title));

  screen->setTextSize(1);
  screen->println();

  screen->setTextSize(2);
  screen->println(F(msg));

  screen->display();
}


void Screen::mainScreen(String datetime, String temperature, String humidity, String msg)
{
  screen->clearDisplay();

  screen->setTextColor(SSD1306_WHITE);   // Draw white text
  screen->setCursor(0, 0);       // Start at top-left corner
  screen->setTextSize(1);
  screen->print(F(" "));
  screen->println(datetime);
  screen->println();

  screen->setTextSize(1);
  screen->print(F("TEMP : "));
  screen->println(temperature);

  screen->println();
  screen->print(F("HUMI : "));
  screen->println(humidity);

  screen->println();
  screen->println(msg);

  screen->display();
}
