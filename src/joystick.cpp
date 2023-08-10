#include "Arduino.h"
#include "joystick.h"

joystick::joystick(int joyPin, String joyName)
{
    pinJoystick = joyPin;
    nameJoystick = joyName;
}

int joystick::readJoystick()
{
    valueJoystick = analogRead(pinJoystick);
    return valueJoystick;
}

void joystick::joystickSerialAusgabe()
{
    Serial.print(nameJoystick);
    Serial.print(": ");
    readJoystick();
    Serial.println(valueJoystick);
}

int joystick::mapJoystick()
{
    readJoystick();
    valueJoystick = map(valueJoystick, 0, 4064, 0, 100);
    return valueJoystick;
}


