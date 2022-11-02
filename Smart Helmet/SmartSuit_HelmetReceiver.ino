#include <RH_ASK.h>
#include <SPI.h>

RH_ASK receiver(2000,2,12,10);

void setup()
{
  Serial.begin(115200);
  if (!receiver.init())
    Serial.println("init failed");
}

void loop()
{
  uint16_t data;
  uint8_t datalen = sizeof(data);
  if (driver.recv((uint8_t*)&data, &datalen))
  {
    Serial.println(data);
  }
}
