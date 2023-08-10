#include <Arduino.h>
#include "outputs.h"

// === StatusLED ===
int LEDButton1 = 3;
int statusLEDButton1 = LOW;

// === Joystick ===


// === MILLIS ===
unsigned long previousMillisButtons = 0;
const long intervallButtons = 50;
unsigned long previousMillisJoystick = 0;
const long intervallJoystick = 4000; // !!!!! noch anpassen !!!!!

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000L);

  // === StatusLED ===
  pinMode(LEDButton1, OUTPUT);
  digitalWrite(LEDButton1, statusLEDButton1);

  // === OLED ===
  monitorInitial();

  // === Taster ===
}

void loop()
{
  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillisButtons) >= intervallButtons)
  {
    checkTasterAll();
    previousMillisButtons = currentMillis;
  }

  if ((currentMillis - previousMillisJoystick) >= intervallJoystick)
  {
    joystickLeftX.joystickSerialAusgabe();
    joystickLeftY.joystickSerialAusgabe();
    
    monitorTransmitter.clear();
    monitorTransmitter.println("--- Smart Car ---");
    monitorTransmitter.println(getDirection(joystickLeftX.mapJoystick(), joystickLeftY.mapJoystick()));
    previousMillisJoystick = currentMillis;
  }

}
