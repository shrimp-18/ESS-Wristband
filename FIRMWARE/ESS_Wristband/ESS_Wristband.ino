
//* ESSync Wristband
//* Firmware Version 1


#include <Wire.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>





// PIN DEFINITIONS
// TFT
#define TFT_CS    -1
#define TFT_DC     3
#define TFT_RST    4
#define TFT_MOSI   6
#define TFT_SCLK   7

// MPU6050
#define MPU_SDA    8
#define MPU_SCL    9

// Button
#define BUTTON_PIN 2

// DISPLAY
Adafruit_ST7789 tft =
Adafruit_ST7789(
TFT_CS,
TFT_DC,
TFT_RST
);



// MPU
Adafruit_MPU6050 mpu;


// SYSTEM STATE
enum MatchState
{
READY,
RUNNING,
PAUSED
};

MatchState state = READY;


// TIMER
const uint16_t MATCH_TIME = 180;

uint16_t remainingTime = MATCH_TIME;

unsigned long lastSecond = 0;

bool timerRunning = false;

// SENSOR DATA
float ax = 0;
float ay = 0;
float az = 0;
float gx = 0;
float gy = 0;
float gz = 0;


// BATTERY
uint8_t batteryPercent = 100;

// BUTTON
bool lastButton = HIGH;

unsigned long lastDebounce = 0;


// DRAW SPLASH
void drawSplash()
{

tft.fillScreen(ST77XX_BLACK);

tft.setTextColor(ST77XX_WHITE);

tft.setTextSize(3);

tft.setCursor(70,30);

tft.println("ESS");

tft.setTextSize(2);

tft.setCursor(18,90);

tft.println("Electronic");

tft.setCursor(42,118);

tft.println("Scoring");

tft.setCursor(50,146);

tft.println("System");

tft.drawLine(
20,
180,
220,
180,
ST77XX_BLUE
);

tft.setCursor(28,195);

tft.setTextColor(ST77XX_CYAN);

tft.println("Initializing...");
}




// DRAW HOME SCREEN
void drawHome()
{

tft.fillScreen(ST77XX_BLACK);

tft.setTextSize(2);

tft.setTextColor(ST77XX_WHITE);

tft.setCursor(55,10);

tft.print("ROUND 1");

drawTimer();

drawStatus();

drawBattery();

}



// DRAW TIMER
void drawTimer()
{

char buf[10];

sprintf(
buf,
"%02d:%02d",
remainingTime/60,
remainingTime%60
);

tft.fillRect(
20,
55,
200,
70,
ST77XX_BLACK
);

tft.setTextColor(ST77XX_WHITE);

tft.setTextSize(5);

tft.setCursor(
25,
65
);

tft.print(buf);

}


// DRAW STATUS
void drawStatus()
{

tft.fillRect(
0,
145,
240,
30,
ST77XX_BLACK
);

tft.setTextSize(2);

switch(state)
{

case READY:

tft.setTextColor(ST77XX_BLUE);

tft.setCursor(72,150);

tft.print("READY");

break;

case RUNNING:

tft.setTextColor(ST77XX_GREEN);

tft.setCursor(55,150);

tft.print("RUNNING");

break;

case PAUSED:

tft.setTextColor(ST77XX_YELLOW);

tft.setCursor(60,150);

tft.print("PAUSED");

break;

}

}




// DRAW BATTERY
void drawBattery()
{

tft.fillRect(
15,
205,
210,
25,
ST77XX_BLACK
);

tft.setTextSize(1);

tft.setTextColor(ST77XX_CYAN);

tft.setCursor(15,210);

tft.print("Battery ");

tft.print(batteryPercent);

tft.print("%");

tft.drawRect(
170,
208,
42,
12,
ST77XX_WHITE
);

int width =
map(
batteryPercent,
0,
100,
0,
40
);

tft.fillRect(
171,
209,
width,
10,
ST77XX_GREEN
);

}

// UPDATE TIMER
void updateTimer()
{
    if (!timerRunning)
        return;

    if (millis() - lastSecond >= 1000)
    {
        lastSecond = millis();

        if (remainingTime > 0)
        {
            remainingTime--;
            drawTimer();
        }
        else
        {
            timerRunning = false;
            state = READY;

            drawStatus();
        }
    }
}


// BUTTON HANDLER

void checkButton()
{
    bool currentButton = digitalRead(BUTTON_PIN);

    if (currentButton != lastButton)
    {
        lastDebounce = millis();
    }

    if (millis() - lastDebounce > 50)
    {
        if (lastButton == HIGH && currentButton == LOW)
        {
            switch (state)
            {
                case READY:

                    state = RUNNING;
                    timerRunning = true;

                    break;

                case RUNNING:

                    state = PAUSED;
                    timerRunning = false;

                    break;

                case PAUSED:

                    state = RUNNING;
                    timerRunning = true;

                    break;
            }

            drawStatus();
        }
    }

    lastButton = currentButton;
}

void readMPU()
{
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t temp;

    mpu.getEvent(
        &accel,
        &gyro,
        &temp
    );

    ax = accel.acceleration.x;
    ay = accel.acceleration.y;
    az = accel.acceleration.z;

    gx = gyro.gyro.x;
    gy = gyro.gyro.y;
    gz = gyro.gyro.z;

    Serial.print("AX: ");
    Serial.print(ax);

    Serial.print(" AY: ");
    Serial.print(ay);

    Serial.print(" AZ: ");
    Serial.print(az);

    Serial.print(" | GX: ");
    Serial.print(gx);

    Serial.print(" GY: ");
    Serial.print(gy);

    Serial.print(" GZ: ");
    Serial.println(gz);
}


void updateBattery()
{
    static unsigned long previous = 0;

    if (millis() - previous < 5000)
        return;

    previous = millis();

    if (batteryPercent > 20)
        batteryPercent--;

    drawBattery();
}


void drawIMUDebug()
{
    tft.fillRect(
        0,
        175,
        240,
        25,
        ST77XX_BLACK
    );

    tft.setTextSize(1);

    tft.setTextColor(ST77XX_WHITE);

    tft.setCursor(5,180);

    tft.print("AZ:");

    tft.print(az,1);

    tft.print(" GX:");

    tft.print(gx,1);
}
void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println("=================================");
    Serial.println(" ESS Referee Wristband");
    Serial.println(" Firmware v0.1");
    Serial.println("=================================");

    pinMode(BUTTON_PIN, INPUT_PULLUP);


    SPI.begin(
        TFT_SCLK,
        -1,
        TFT_MOSI
    );

    tft.init(240,240);

    tft.setRotation(0);

    drawSplash();

    delay(2000);

    Wire.begin(
        MPU_SDA,
        MPU_SCL
    );


    if(!mpu.begin())
    {
        tft.fillScreen(ST77XX_RED);

        tft.setTextColor(ST77XX_WHITE);

        tft.setTextSize(2);

        tft.setCursor(15,110);

        tft.println("MPU6050 NOT FOUND");

        Serial.println("MPU6050 FAILED");

        while(true);
    }

    Serial.println("MPU6050 OK");

    drawHome();

    lastSecond = millis();
}


void loop()
{
    readMPU();

    checkButton();

    updateTimer();

    updateBattery();

    drawIMUDebug();

    delay(10);
}