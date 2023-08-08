#ifndef button_h
#define button_h

#include <Arduino.h>



class button {

    private:
        int pinButton;
        bool buttonStatus = 0;
        int buttonRead = 0;

        unsigned long previousMillis = 0;


    public:
        int buttonNumber;
        String buttonName;
        button(int pin, int btnNr, String btnname);

        int readButton();

        void setButtonStatusActive();
        void setButtonStatusInactive();
        bool getButtonStatus();
        void toggleButtonStatus();

        void buttonSerialAusgabe();

        void setButtonNumber(int number);
        int getButtonNumber();




};



#endif
