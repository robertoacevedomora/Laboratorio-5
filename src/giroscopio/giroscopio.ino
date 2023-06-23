/*
  IMU Capture
  This example uses the on-board IMU to start reading acceleration and gyroscope
  data from on-board IMU and prints it to the Serial Monitor for one second
  when the significant motion is detected.
  You can also use the Serial Plotter to graph the data.
  The circuit:
  - Arduino Nano 33 BLE or Arduino Nano 33 BLE Sense board.
  Created by Don Coleman, Sandeep Mistry
  Modified by Dominic Pajak, Sandeep Mistry
  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>

const float accelerationThreshold = 2.5; // threshold of significant in G's
//Quitar cantidad de muestras

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
}
}

void loop() {
  float aX, aY, aZ, gX, gY, gZ;
  unsigned long timestamp = millis();

  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
      // read the acceleration and gyroscope data
    IMU.readAcceleration(aX, aY, aZ);
    IMU.readGyroscope(gX, gY, gZ);

      // print the data in CSV format
      Serial.print('\t');
      Serial.print(aX);
      Serial.print('\t');
      Serial.print(aY);
      Serial.print('\t');
      Serial.print(aZ);
      Serial.print('\t');
      Serial.print(gX);
      Serial.print('\t');
      Serial.print(gY);
      Serial.print('\t');
      Serial.println(gZ);
      //Serial.println();
  }
}
