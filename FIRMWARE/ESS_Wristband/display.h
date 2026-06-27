#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

extern Adafruit_ST7789 tft;

void initDisplay();

void splashScreen();

void readyScreen();

void errorScreen(String msg);

void drawTimer(uint16_t seconds);

void drawStatus(String status, uint16_t color);

void drawRound(uint8_t round);

#endif