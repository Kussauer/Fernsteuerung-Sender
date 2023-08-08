#include "Arduino.h"
#include "button.h"

button::button(int pin, int btnNr, String btnName)
{
    pinButton = pin;
    pinMode(pinButton, OUTPUT);
    buttonNumber = btnNr;
    buttonName = btnName;
}

void button::setButtonNumber(int number)
{
    buttonNumber = number;
}

int button::getButtonNumber()
{
    return buttonNumber;
}

void button::buttonSerialAusgabe()
{
    Serial.print("Taster ");
    Serial.print(buttonNumber);
    Serial.println(" gedrückt !");
}

bool button::getButtonStatus()
{
    return buttonStatus;
}

int button::readButton()
{
    buttonRead = digitalRead(pinButton);
    return buttonRead;
}

void button::setButtonStatusActive()
{
    buttonStatus = 1;
}

void button::setButtonStatusInactive()
{
    buttonStatus = 0;

}

void button::toggleButtonStatus()
{
    /*
    switch (buttonStatus)
    {
    case 1:
        buttonStatus = 0;
        break;

    case 0:
        buttonStatus = 1;
        break;
    
    default:
        Serial.println("Probleme im ToggleButtonStatus!!!!");
        break;
    }
    */

   buttonStatus = !buttonStatus;
   delay(250);

}