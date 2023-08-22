#include <Arduino.h>
#include "outputs.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// === StatusLED ===
int LEDButton1 = 3;
int statusLEDButton1 = LOW;

// === Joystick ===

// === Transmitter ===
// CE - 9
// CDN - 10
RF24 radio(9, 10);

const byte address[6] = "00001"; // Adresse



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

  // === Transmitter ===
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
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

  // === Transmitter ===
  char stBtn[200];
  readButtonStatusAsJSON().toCharArray(stBtn, 200);
  radio.write(&stBtn, sizeof(stBtn));
  delay(2000); // anpassen !!!
}


