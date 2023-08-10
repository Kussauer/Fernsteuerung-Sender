#ifndef joystick_h
#define joystick_h

#include <Arduino.h>

class joystick
{

private:
    int valueJoystick;
    int pinJoystick;

public:
    String nameJoystick;

    joystick(int joyPin, String joyName);

    int readJoystick();
    void joystickSerialAusgabe();

    int mapJoystick();
    String getDirection(int xAxis, int yAxis);
    
};

#endif