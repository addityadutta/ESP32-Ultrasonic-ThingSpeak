ESP32 Ultrasonic Sensor to ThingSpeak IoT

This project uses an ESP32 and an HC-SR04 ultrasonic sensor to measure distance and send data to the ThingSpeak cloud using HTTP.
Components:
* ESP32 Development Board
* HC-SR04 Ultrasonic Sensor
* ThingSpeak Account

Connections:
Sensor Pin - ESP32 Pin
VCC - 5V
GND - GND
TRIG - GPIO 5
ECHO - GPIO 18

Working:
1. The ESP32 connects to Wi-Fi.
2. Reads distance from the ultrasonic sensor.
3. Sends the data to ThingSpeak every 15 seconds for real-time monitoring.

Platform:
Works on Wokwi , Things speak IoT Simulator

Author:
Additya Dutta

