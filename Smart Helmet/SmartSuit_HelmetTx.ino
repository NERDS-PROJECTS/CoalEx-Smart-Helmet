#include <RH_ASK.h>
#include <SPI.h>

int state = 0;
RH_ASK driver;

int piezo1 = A0;
int piezo2 = A1;
int piezo3 = A2;
int piezo4 = A3;
int piezo5 = A4;
void setup()
{
  driver.init();
  Serial.begin(9600);
  pinMode(piezo1,INPUT);
  pinMode(piezo2,INPUT);
  pinMode(piezo3,INPUT);
  pinMode(piezo4,INPUT);
  pinMode(piezo5,INPUT);
}

void loop()
{
    uint16_t data1 = analogRead(piezo1);
    uint16_t data2 = analogRead(piezo2);
    uint16_t data3 = analogRead(piezo3);
    uint16_t data4 = analogRead(piezo4);
    uint16_t data5 = analogRead(piezo5);

    int avg = (data1+data2+data3+data4+data5)./5;
    driver.send((uint8_t *)&avg, sizeof(avg));
    driver.waitPacketSent();
    delay(200);
}