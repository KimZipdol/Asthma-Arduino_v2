#include <Arduino.h>
#include <SoftwareSerial.h>
#include "src/Omron_D6FPH.h"

Omron_D6FPH mySensor;

//블루투스 연결
SoftwareSerial BTSerial(4, 5);

void setup()
{
  Serial.begin(115200);
  /*
  if(!BLE.begin())
    Serial.println("BLE begin failed");
    */
  BTSerial.begin(9600);
    
  mySensor.begin(MODEL_5050AD3);
}

void loop()
{
  float pressure = mySensor.getPressure();
  /*if (isnan(pressure))
  {
    Serial.println("Error: Could not read pressure data");
  }
  else
  {
    Serial.println(pressure);
  }*/

  if(BTSerial.available())
  {
    BTSerial.write(pressure);
    BTSerial.flush();
  }

}
