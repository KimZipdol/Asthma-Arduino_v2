#include <Arduino.h>
#include <Wire.h>
#include "src/Omron_D6FPH.h"
#include <SoftwareSerial.h> // 블루투스 통신을 위한 SoftwareSerial 라이브러리를 불러온다. 

Omron_D6FPH mySensor;
SoftwareSerial BTSerial(4, 5); // SoftwareSerial(RX, TX)

void setup()
{
  BTSerial.begin(9600); 
  Serial.begin(9600); 
}

void loop()
{
  float pressure = mySensor.getPressure();
  if (isnan(pressure))
  {
    BTSerial.println("Error: Could not read pressure data");
  }
  else
  {
    BTSerial.println(pressure);
  }

}
