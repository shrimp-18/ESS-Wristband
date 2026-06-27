#ifndef IMU_H
#define IMU_H

#include <Adafruit_MPU6050.h>

extern Adafruit_MPU6050 mpu;

bool initMPU();

void updateIMU();

extern float ax;
extern float ay;
extern float az;

extern float gx;
extern float gy;
extern float gz;

#endif