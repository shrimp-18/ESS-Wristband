#include "display.h"
#include "pins.h"
#include "config.h"

#include <SPI.h>

Adafruit_ST7789 tft =
Adafruit_ST7789(
    TFT_CS,
    TFT_DC,
    TFT_RST
);

void initDisplay()
{
    SPI.begin(
        TFT_SCLK,
        -1,
        TFT_MOSI
    );

    tft.init(240,240);

    tft.setRotation(0);

    tft.fillScreen(ST77XX_BLACK);
}

void drawSplash()
{
    tft.fillScreen(ST77XX_BLACK);

    tft.setCursor(25,50);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(3);
    tft.println("ESS");

    tft.setCursor(18,100);
    tft.setTextSize(2);
    tft.println("Referee Band");

    tft.setCursor(20,180);
    tft.setTextColor(ST77XX_BLUE);
    tft.println("Initializing...");
}

void drawReadyScreen()
{
    tft.fillScreen(ST77XX_BLACK);

    tft.setCursor(20,20);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_RED);
    tft.println("ROUND 1");

    tft.setCursor(25,80);
    tft.setTextSize(4);
    tft.setTextColor(ST77XX_WHITE);
    tft.println("03:00");

    tft.setCursor(55,180);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_GREEN);
    tft.println("READY");
}