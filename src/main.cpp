#include <Arduino.h>
/* #include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h" */
#include "button.h"
#include "oledDisplay.h"

// === OLED ===
/* #define I2C_ADDRESS 0x3C // Adresse
SSD1306AsciiWire monitorTransmitter; // Displayname  */

// === Taster ===

button taster1(8, 1, "Taster 1");
button taster2(9, 2, "taster 2");
button taster3(10, 3, "Taster 3");
button taster4(11, 4, "Taster 4");
button taster5(12, 5, "Taster 5");



// === StatusLED ===
int LEDButton1 = 3;
int statusLEDButton1 = LOW;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000L);

  // === StatusLED ===
  pinMode(LEDButton1, OUTPUT);
  digitalWrite(LEDButton1, statusLEDButton1);

  // === OLED ===
 /*  monitorTransmitter.begin(&Adafruit128x64, I2C_ADDRESS); // OLED 0,96
  monitorTransmitter.setFont(Arial_bold_14);
  monitorTransmitter.displayRemap(true);              // Drehung 180 Grad
  monitorTransmitter.setScrollMode(SCROLL_MODE_AUTO); // AutoScroll
  monitorTransmitter.setLetterSpacing(2);
  monitorTransmitter.println("Systemstart"); */

  monitorInitial();

  // === Taster ===
  
}

void loop()
{

if (taster1.readButton() == 1)
{
 taster1.toggleButtonStatus();
 taster1.buttonSerialAusgabe();
 monitorTransmitter.clear();
 monitorTransmitter.println(taster1.buttonName);
 if (taster1.getButtonStatus() == 1){
  monitorTransmitter.println("aktiviert");
 }
 if (taster1.getButtonStatus() == 0) {
  monitorTransmitter.println("deaktiviert");
 }
 Serial.println(taster1.getButtonStatus());
}


}
