# ESP8266 Weather Monitoring System

A WiFi-connected weather station built on the ESP8266 (NodeMCU) that reads temperature, humidity, and rainfall data — serving it via a local web page and logging it to ThingSpeak every 10 seconds.

---

## Table of Contents

- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Connections](#circuit-connections)
- [Setup](#setup)
- [Configuration](#configuration)
- [How It Works](#how-it-works)
- [ThingSpeak Fields](#thingspeak-fields)
- [Notes](#notes)
- [License](#license)

---

## Features

- Reads temperature (°C and °F) and humidity via DHT11/DHT22
- Reads analog rainfall level via a rain sensor module
- Hosts a live HTML dashboard at the ESP8266's local IP address
- Uploads sensor readings to ThingSpeak over HTTP every 10 seconds

---

## Hardware Requirements

| Component | Details |
|---|---|
| Microcontroller | ESP8266 (NodeMCU v2/v3 or equivalent) |
| Temperature/Humidity sensor | DHT11 or DHT22 |
| Rain sensor module | Analog output (AO) type |
| Jumper wires | — |
| WiFi network | 2.4 GHz |

---

## Circuit Connections

**DHT11/DHT22**

| Sensor Pin | ESP8266 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| Data | D4 (GPIO2) |

**Rain Sensor**

| Sensor Pin | ESP8266 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| AO | A0 |

---

## Setup

1. Install the [Arduino IDE](https://www.arduino.cc/en/software) and add ESP8266 board support via Board Manager:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```

2. Install the required libraries from the Library Manager:
   - `ESP8266WiFi` (bundled with ESP8266 board package)
   - `ESP8266WebServer` (bundled with ESP8266 board package)
   - `DHT sensor library` by Adafruit

3. Clone this repo and open `Weather/Weather.ino` in the Arduino IDE.

4. Follow the [Configuration](#configuration) section, then upload to your board.

---

## Configuration

Open `Weather/Weather.ino` and update these values before uploading:

```cpp
// WiFi credentials
const char* ssid     = "your_wifi_name";
const char* password = "your_wifi_password";

// ThingSpeak API key
const String apiKey = "your_api_key";
```

To get a ThingSpeak API key: create a free account at [thingspeak.com](https://thingspeak.com), create a channel with 4 fields, and copy the **Write API Key**.

---

## How It Works

```
Boot → Connect to WiFi → Start HTTP server on port 80
                                  ↓
Loop every 10 s:
  1. Read DHT sensor  → temperature (°C, °F) + humidity
  2. Read A0          → rain sensor analog value
  3. Serve /          → HTML page with live readings
  4. POST to ThingSpeak → log all 4 fields
```

- The IP address assigned by your router is printed to the Serial Monitor on boot.
- Navigate to that IP in any browser on the same network to see the live dashboard.

---

## ThingSpeak Fields

| Field | Data |
|---|---|
| Field 1 | Rain sensor value (analog, 0–1023) |
| Field 2 | Temperature (°C) |
| Field 3 | Temperature (°F) |
| Field 4 | Humidity (%) |

---

## Notes

- The update interval is `delay(10000)` (10 s). ThingSpeak's free tier requires at least 15 s between updates — lower the delay only if you upgrade your plan.
- If DHT readings return `nan`, check the data pin connection and confirm the correct `DHTTYPE` is defined (`DHT11` or `DHT22`).
- The rain sensor analog value decreases as more water is detected (varies by module).

---

## Hardware Preview

<center>
  <img src="https://github.com/user-attachments/assets/06612ff6-346e-4c00-a320-5f4cc96dd8a0">
</center>

<center>
  <img src="https://github.com/user-attachments/assets/562e4909-3975-4c64-8f48-2af8ae008490">
</center>

---

## License

This project is open-source. Feel free to modify and distribute it.

**Author:** Vipanshu Suman
