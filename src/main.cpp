#include <Arduino.h>
#include "outputs.h"

// === StatusLED ===
int LEDButton1 = 3;
int statusLEDButton1 = LOW;

// === Joystick ===

int sensorWert1 = 0;
int sensorWert2 = 0;

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

  sensorWert1 = analogRead(A3);
  sensorWert2 = analogRead(A2);

  Serial.print("Wert 1 = ");
  Serial.println(sensorWert1);

  Serial.print("Wert 2 = ");
  Serial.println(sensorWert2);
  Serial.println("---------------");

  sensorWert1 = map(sensorWert1, 0, 4064, 0, 100);
  sensorWert2 = map(sensorWert2, 0, 4064, 0, 100);

  Serial.print("Mapping-Wert 1 = ");
  Serial.println(sensorWert1);

  Serial.print("Mapping-Wert 2 = ");
  Serial.println(sensorWert2);
  Serial.println("===============");

  delay(3000);
}
