#include <Arduino.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C // Adresse
SSD1306AsciiWire monitorTransmitter; // Displayname 


void monitorInitial ()
{
   monitorTransmitter.begin(&Adafruit128x64, I2C_ADDRESS); // OLED 0,96
  monitorTransmitter.setFont(Arial_bold_14);
  monitorTransmitter.displayRemap(true);              // Drehung 180 Grad
  monitorTransmitter.setScrollMode(SCROLL_MODE_AUTO); // AutoScroll
  monitorTransmitter.setLetterSpacing(2);
  monitorTransmitter.println("Systemstart"); 
}