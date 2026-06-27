#include "config.h"
#include "pins.h"
#include "globals.h"

#include "display.h"
#include "imu.h"

bool timerRunning = false;

uint8_t currentRound = 1;

uint16_t remainingTime = 180;

unsigned long previousMillis = 0;

SystemState currentState = BOOT;

void setup()
{
    Serial.begin(115200);

    pinMode(
        BUTTON_PIN,
        INPUT_PULLUP
    );

    initDisplay();

    drawSplash();

    if(!initMPU())
    {
        tft.fillScreen(ST77XX_RED);

        while(1);
    }

    delay(SPLASH_TIME);

    drawReadyScreen();
}

void loop()
{
    updateIMU();

    Serial.print(ax);
    Serial.print(",");

    Serial.print(ay);
    Serial.print(",");

    Serial.println(az);

    delay(50);
}