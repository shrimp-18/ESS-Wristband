#ifndef ENUMS_H
#define ENUMS_H

enum SystemState
{
    BOOT,
    READY,
    RUNNING,
    PAUSED,
    CALIBRATION,
    SETTINGS,
    ERROR_STATE
};

enum GestureType
{
    NONE,
    START_GESTURE,
    STOP_GESTURE
};

#endif