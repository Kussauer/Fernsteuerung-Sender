#include <Arduino.h>
#include "outputs.h"


// === StatusLED ===
int LEDButton1 = 3;
int statusLEDButton1 = LOW;

// === MILLIS ===
unsigned long previousMillisButtons = 0;
const long intervallButtons = 50;

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
}
