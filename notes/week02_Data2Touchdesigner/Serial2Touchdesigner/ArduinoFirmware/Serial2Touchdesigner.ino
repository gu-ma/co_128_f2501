/*
For this setup we will use the Seeedstudio XIAO BLE Sense nRF52840 microcontroller.
sensors are in this microcontroller already built in: Acceleration and gyroscope sensors are on board.
If you need more information about the board and the setup process in the Arduino IDE.
Check these pages:
 
-> Setting up the board in Arduino IDE:
    -------------------------------
    https://wiki.seeedstudio.com/XIAO_BLE/

-> How to use the 3-axis accelerometer and 3-axis gyroscope:
    -----------------------------------------------------------
    https://github.com/Seeed-Studio/wiki-documents/blob/docusaurus-version/docs/Sensor/SeeedStudio_XIAO/SeeedStudio_XIAO_nRF52840-Sense/XIAO-BLE-Sense-IMU-Usage.md
*/


#include "LSM6DS3.h"
#include "Wire.h"

//Create a instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A

void setup() {
    Serial.begin(9600);
    while (!Serial);
    if (myIMU.begin() != 0) {
        Serial.println("Device error");
    } else {
        Serial.println("Device OK!");
    }
}

void loop() {
    // Read all values
    float accX = myIMU.readFloatAccelX();
    float accY = myIMU.readFloatAccelY();
    float accZ = myIMU.readFloatAccelZ();
    float gyroX = myIMU.readFloatGyroX();
    float gyroY = myIMU.readFloatGyroY();
    float gyroZ = myIMU.readFloatGyroZ();
    float temp = myIMU.readTempC();
    
    // Output in CSV format: accX,accY,accZ,gyroX,gyroY,gyroZ,temp
    Serial.print(accX, 4);
    Serial.print(",");
    Serial.print(accY, 4);
    Serial.print(",");
    Serial.print(accZ, 4);
    Serial.print(",");
    Serial.print(gyroX, 4);
    Serial.print(",");
    Serial.print(gyroY, 4);
    Serial.print(",");
    Serial.print(gyroZ, 4);
    Serial.print(",");
    Serial.println(temp, 4);

    delay(100);  // 10Hz update rate
}