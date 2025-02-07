# ESP8266 Weather Station with ThingSpeak Integration

## Overview
This project uses an ESP8266 microcontroller to create a weather station that measures temperature, humidity, and rain levels. The data is displayed on a web server and uploaded to ThingSpeak for remote monitoring.

## Components Required
- ESP8266 (e.g., NodeMCU)
- DHT11 or DHT22 temperature and humidity sensor
- Rain sensor module
- Jumper wires
- WiFi network

## Circuit Connections
- **DHT Sensor**
  - VCC → 3.3V
  - GND → GND
  - Data → GPIO2 (D4 on NodeMCU)
- **Rain Sensor**
  - AO → A0 (Analog input on ESP8266)
  - VCC → 3.3V
  - GND → GND

## Installation
1. Install the **Arduino IDE** and add the ESP8266 board support.
2. Install the required libraries:
   - `ESP8266WiFi`
   - `ESP8266WebServer`
   - `DHT` (for temperature and humidity readings)
3. Clone this repository or copy the code into an Arduino sketch.

## Configuration
- Update the WiFi credentials in the code:
  ```cpp
  const char* ssid = "your_wifi_name";
  const char* password = "your_wifi_password";
  ```
- Set your **ThingSpeak API key**:
  ```cpp
  const String apiKey = "your_api_key";
  ```

## Code Explanation
- Connects to WiFi and starts a local web server.
- Reads data from the DHT11 sensor (temperature & humidity) and rain sensor.
- Displays data on a web page.
- Sends sensor data to ThingSpeak every 10 seconds.

## Usage
1. Upload the code to your ESP8266.
2. Open the Serial Monitor to check the IP address assigned by the router.
3. Access the web interface by entering the ESP8266's IP address in a browser.
4. Monitor data on ThingSpeak.

<center>
  <img src="https://github.com/user-attachments/assets/06612ff6-346e-4c00-a320-5f4cc96dd8a0">
</center>

## ThingSpeak Data Upload Format
```
Field1: Rain Sensor Value
Field2: Temperature (°C)
Field3: Temperature (°F)
Field4: Humidity (%)
```
<center>
  <img src="https://github.com/user-attachments/assets/562e4909-3975-4c64-8f48-2af8ae008490">
  <img src="https://github.com/user-attachments/assets/5524a3e7-f45b-4855-8864-821051233db0">
</center>

## Notes
- Ensure a stable WiFi connection for ThingSpeak updates.
- Modify the delay (`delay(10000)`) for different update intervals.

## License
This project is open-source. Feel free to modify and distribute it.

## Author
Vipanshu Suman
