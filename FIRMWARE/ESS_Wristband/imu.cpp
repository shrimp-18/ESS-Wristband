#include "imu.h"
#include "pins.h"

#include <Wire.h>

Adafruit_MPU6050 mpu;

float ax,ay,az;
float gx,gy,gz;

bool initMPU()
{
    Wire.begin(
        MPU_SDA,
        MPU_SCL
    );

    if(!mpu.begin())
        return false;

    return true;
}

void updateIMU()
{
    sensors_event_t a,g,temp;

    mpu.getEvent(
        &a,
        &g,
        &temp
    );

    ax=a.acceleration.x;
    ay=a.acceleration.y;
    az=a.acceleration.z;

    gx=g.gyro.x;
    gy=g.gyro.y;
    gz=g.gyro.z;
}