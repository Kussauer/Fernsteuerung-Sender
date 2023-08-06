#include <Arduino.h>


// === Taster ===
int taster;
int analogWert = 0;
int value = 0;

int tasterAbfrage()
{
  analogWert = analogRead(A5);
  return analogWert;
}



void setup()
{
  Serial.begin(115200);

}

void loop()
{
  value = tasterAbfrage();

  if ((value <= 4065) && (value >= 4059))
  {
    Serial.println("Taster 1");
  }

  if ((value <= 4039) && (value >= 4035))
  {
    Serial.println("Taster 2");
  }

  if ((value <= 3925) && (value >= 3915))
  {
    Serial.println("Taster 3");
  }

  if ((value <= 3750) && (value >= 3740))
  {
    Serial.println("Taster 4");
  }

  Serial.println(value);
  delay(250);

}
