# Webserver to display realtime IR sensor data

## Date: 30-11-2024


## Features
  -  Web Server for ESP32
  - IR Sensor Integration to monitor objects in real-time
  - Display sensor data in a web interface



### Prerequisites
- List the required tools or dependencies:
  - ESP32 board
  - Platform.io
  - IR sensor module

### Steps
 -setup platform.io 
 -create new project with  Arduino framework
 -choose your ESP32 board 
 -go to platformio.ino and decleare 'monitor_speed = 115200'
 -copy the main.cpp file
 -initialize ssid and password
 -connect the sensor's OUT pin to ESP's GPIO 4 pin, VCC to 3V and GND to ESP's GND pin
 -upload the code
