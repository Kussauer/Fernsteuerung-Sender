#include "button.h"
#include "oledDisplay.h"
#include "joystick.h"

// === Initialisierung der Taster (PIN / Nummer / Name)
button taster1(2, 1, "Taster 1");
button taster2(3, 2, "Taster 2");
button taster3(4, 3, "Taster 3");
button taster4(5, 4, "Taster 4");
button taster5(6, 5, "Taster 5");

// === Initialisierung der Joysticks (PIN / Name)
joystick joystickLeftX(A3, "LinksX");
joystick joystickLeftY(A2, "LinksY");

void checkTaster1()
{
    if (taster1.readButton() == 1)
    {
        taster1.toggleButtonStatus();
        taster1.buttonSerialAusgabe();
        monitorTransmitter.clear();
        monitorTransmitter.println("-- Smart Car --");
        monitorTransmitter.println(taster1.buttonName);
        if (taster1.getButtonStatus() == 1)
        {
            monitorTransmitter.println("aktiviert");
        }
        if (taster1.getButtonStatus() == 0)
        {
            monitorTransmitter.println("deaktiviert");
        }
        Serial.println(taster1.getButtonStatus());
    }
}

void checkTaster2()
{
    if (taster2.readButton() == 1)
    {
        taster2.toggleButtonStatus();
        taster2.buttonSerialAusgabe();
        monitorTransmitter.clear();
        monitorTransmitter.println("-- Smart Car --");
        monitorTransmitter.println(taster2.buttonName);
        if (taster2.getButtonStatus() == 1)
        {
            monitorTransmitter.println("aktiviert");
        }
        if (taster2.getButtonStatus() == 0)
        {
            monitorTransmitter.println("deaktiviert");
        }
        Serial.println(taster2.getButtonStatus());
    }
}

void checkTaster3()
{
    if (taster3.readButton() == 1)
    {
        taster3.toggleButtonStatus();
        taster3.buttonSerialAusgabe();
        monitorTransmitter.clear();
        monitorTransmitter.println("-- Smart Car --");
        monitorTransmitter.println(taster3.buttonName);
        if (taster3.getButtonStatus() == 1)
        {
            monitorTransmitter.println("aktiviert");
        }
        if (taster3.getButtonStatus() == 0)
        {
            monitorTransmitter.println("deaktiviert");
        }
        Serial.println(taster3.getButtonStatus());
    }
}

void checkTaster4()
{
    if (taster4.readButton() == 1)
    {
        taster4.toggleButtonStatus();
        taster4.buttonSerialAusgabe();
        monitorTransmitter.clear();
        monitorTransmitter.println("-- Smart Car --");
        monitorTransmitter.println(taster4.buttonName);
        if (taster4.getButtonStatus() == 1)
        {
            monitorTransmitter.println("aktiviert");
        }
        if (taster4.getButtonStatus() == 0)
        {
            monitorTransmitter.println("deaktiviert");
        }
        Serial.println(taster4.getButtonStatus());
    }
}

void checkTaster5()
{
    if (taster5.readButton() == 1)
    {
        taster5.toggleButtonStatus();
        taster5.buttonSerialAusgabe();
        monitorTransmitter.clear();
        monitorTransmitter.println("-- Smart Car --");
        monitorTransmitter.println(taster5.buttonName);
        if (taster5.getButtonStatus() == 1)
        {
            monitorTransmitter.println("aktiviert");
        }
        if (taster5.getButtonStatus() == 0)
        {
            monitorTransmitter.println("deaktiviert");
        }
        Serial.println(taster5.getButtonStatus());
    }
}

void checkTasterAll()
{
    checkTaster1();
    checkTaster2();
    checkTaster3();
    checkTaster4();
    checkTaster5();
}

String getDirection(int xAxis, int yAxis)
{
    /*
    0-RW//Li-25-langsamRW//langsamLi-45
    Stopp
    55-langsamVW//langsamRe-75-VW//Re-100
    */

    int x = xAxis;
    int y = yAxis;

    if ((x >= 45 && x <= 55) && (y >= 45 && y <= 55))
    {
        return "Stop";
    }

    if ((x >= 45 && x <= 55) && (y >= 56 && y <= 75))
    {
        return "SlowFW";
    }

    if ((x >= 45 && x <= 55) && (y >= 76 && y <= 100))
    {
        return "Forward";
    }

    if ((x >= 45 && x <= 55) && (y >= 25 && y <= 44))
    {
        return "SlowBW";
    }

    if ((x >= 45 && x <= 55) && (y >= 0 && y <= 24))
    {
        return "Backwards";
    }

    if ((x >= 25 && x <= 44) && (y >= 45 && y <= 55))
    {
        return "SlowLeft";
    }

    if ((x >= 0 && x <= 24) && (y >= 45 && y <= 55))
    {
        return "Left";
    }

    if ((x >= 56 && x <= 75) && (y >= 45 && y <= 55))
    {
        return "SlowRight";
    }

    if ((x >= 76 && x <= 100) && (y >= 45 && y <= 55))
    {
        return "Right";
    }
}

//  ====== Transmitter ===

String readButtonStatusAsJSON()
{
    int status1 = taster1.getButtonStatus();
    int status2 = taster2.getButtonStatus();
    int status3 = taster3.getButtonStatus();
    int status4 = taster4.getButtonStatus();
    int status5 = taster5.getButtonStatus();

    String result = "{";
    result = result + "b1:" + String(status1, 2) + ","; // Status Taster 1
    result = result + "b2:" + String(status1, 2) + ","; // Status Taster 2
    result = result + "b3:" + String(status1, 2) + ","; // Status Taster 3
    result = result + "b4:" + String(status1, 2) + ","; // Status Taster 4
    result = result + "b5:" + String(status2, 2);       // Status Taster 5
    result = result + "}";

    Serial.println(result);

    return result;
}