#include <Arduino.h>
#include <Wire.h>
#include "src/Omron_D6FPH.h"

Omron_D6FPH mySensor;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  mySensor.begin(MODEL_5050AD3);
}

void loop()
{
  float pressure = mySensor.getPressure();
  if (isnan(pressure))
  {
    Serial.println("Error: Could not read pressure data");
  }
  else
  {
    Serial.println(pressure);
  }

}
