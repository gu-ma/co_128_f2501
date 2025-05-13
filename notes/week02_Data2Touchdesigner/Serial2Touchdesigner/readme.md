IMU Data Streaming from XIAO BLE Sense to TouchDesigner
This project allows you to stream IMU (Inertial Measurement Unit) data from a Seeedstudio XIAO BLE Sense nRF52840 microcontroller to TouchDesigner in real time.
Hardware Requirements

Seeedstudio XIAO BLE Sense nRF52840 microcontroller
USB cable for connecting the microcontroller to your computer

Software Requirements

Arduino IDE
TouchDesigner

Files in this Project

Serial2Touchdesigner.ino: Arduino sketch for reading IMU data from the XIAO BLE Sense and sending it over serial
Serial2Touchdesigner.4.toe: TouchDesigner file for receiving and visualizing the IMU data

Setup Instructions
Arduino Setup

Follow the instructions to set up the Seeedstudio XIAO BLE Sense in Arduino IDE:

Guide: https://wiki.seeedstudio.com/XIAO_BLE/


Install the required LSM6DS3 library via the Arduino Library Manager
Upload the Serial2Touchdesigner.ino sketch to your XIAO BLE Sense board
The sketch will read the following data from the on-board IMU and send it over serial:

Acceleration (X, Y, Z)
Gyroscope (X, Y, Z)
Temperature



TouchDesigner Setup

Open TouchDesigner and load the Serial2Touchdesigner.4.toe file
Configure the serial port in TouchDesigner to match the port your XIAO BLE Sense is connected to
The data should now be streaming from the microcontroller to TouchDesigner

How It Works
Arduino Sketch
The Arduino sketch initializes the LSM6DS3 IMU and reads accelerometer, gyroscope, and temperature data at 10Hz (every 100ms). The data is formatted as CSV and sent over the serial port at 9600 baud in the following format:
accX,accY,accZ,gyroX,gyroY,gyroZ,temp
TouchDesigner
The TouchDesigner file receives the serial data, parses the CSV format, and creates visualizations or processing of the IMU data.
Additional Resources

XIAO BLE Sense IMU Usage Documentation
LSM6DS3 Datasheet

Troubleshooting

If no data is received in TouchDesigner, check that the correct serial port is selected
Verify the baud rate in TouchDesigner matches the Arduino sketch (9600)
Make sure the Arduino sketch is uploaded successfully and the device shows "Device OK!" in the serial monitor

License
This project is open source and available under the MIT License.
