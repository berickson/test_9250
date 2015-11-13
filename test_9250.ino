#include <I2Cdev.h>

#include <Wire.h>

#include "Mpu9150.h"

Mpu9150 mpu;

unsigned long last_log;
void setup() {
  last_log = millis();
  Serial.begin(115200);
  mpu.setup();
  // put your setup code here, to run once:

}

void loop() {
  mpu.execute();
  if(millis() - last_log >100) {
    Serial.println(mpu.ground_angle());
    last_log = millis();
  }
  delay(1);
  // put your main code here, to run repeatedly:

}
