<p align="center"><h1 align="center">WEATHER-MONITORING-SYSTEM</h1></p>
<p align="center">
<em><code>❯ IoT Weather Station with ESP8266 and ThingSpeak Cloud Integration</code></em>
</p>
<p align="center">
<img src="https://img.shields.io/github/license/vipu18/Weather-Monitoring-System?style=default&logo=opensourceinitiative&logoColor=white&color=0080ff" alt="license">
<img src="https://img.shields.io/github/last-commit/vipu18/Weather-Monitoring-System?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
<img src="https://img.shields.io/github/languages/top/vipu18/Weather-Monitoring-System?style=default&color=0080ff" alt="repo-top-language">
<img src="https://img.shields.io/github/languages/count/vipu18/Weather-Monitoring-System?style=default&color=0080ff" alt="repo-language-count">
</p>
<p align="center"><!-- default option, no dependency badges. -->
</p>
<p align="center">
<!-- default option, no dependency badges. -->
</p>
<br>

##  Table of Contents

- [ Overview](#-overview)
- [ Features](#-features)
- [ Project Structure](#-project-structure)
  - [ Project Index](#-project-index)
- [ Getting Started](#-getting-started)
  - [ Prerequisites](#-prerequisites)
  - [ Installation](#-installation)
  - [ Usage](#-usage)
  - [ Testing](#-testing)
- [ Project Roadmap](#-project-roadmap)
- [ Contributing](#-contributing)
- [ License](#-license)
- [ Acknowledgments](#-acknowledgments)

---

##  Overview

The Weather Monitoring System is a comprehensive IoT-based environmental monitoring solution built around the ESP8266 microcontroller that seamlessly integrates hardware sensors with cloud connectivity for real-time weather data collection and remote monitoring. This project leverages WiFi capabilities to create a distributed weather network that automatically uploads sensor readings to ThingSpeak every 10 seconds for continuous data visualization and analysis.

The system features dual monitoring interfaces including a local web server for immediate data access and cloud synchronization through ThingSpeak's IoT platform. With support for temperature, humidity, pressure, and rainfall measurements, this weather station provides comprehensive environmental monitoring suitable for agricultural applications, research projects, and personal weather tracking with both local and remote accessibility.

---

##  Features

<code>❯ **Environmental Sensor Integration**</code>
- **Multi-Parameter Monitoring**: Simultaneous measurement of temperature (°C), humidity (%), atmospheric pressure (Pa), and rainfall levels
- **DHT11/DHT22 Compatibility**: Flexible sensor support for both DHT11 and DHT22 temperature and humidity sensors
- **Rain Detection System**: Analog rain sensor with threshold-based precipitation monitoring and intensity measurement
- **High-Precision Readings**: Calibrated sensor readings with proper error handling and data validation

<code>❯ **Connectivity & Cloud Integration**</code>
- **WiFi Network Integration**: Seamless connection to existing wireless networks with automatic reconnection capabilities
- **Local Web Server**: Built-in HTTP server providing real-time sensor data display through any web browser
- **ThingSpeak Cloud Platform**: Automatic data upload to ThingSpeak with structured field mapping for remote monitoring
- **Real-time Data Streaming**: Continuous 10-second interval updates for current weather conditions and historical tracking

<code>❯ **System Architecture & Management**</code>
- **Arduino IDE Compatible**: Standard Arduino development environment with ESP8266 board support
- **Serial Monitor Debugging**: Comprehensive logging and system status reporting for troubleshooting
- **Configurable Update Intervals**: Customizable data transmission frequency for different monitoring requirements
- **Error Recovery Mechanisms**: Robust WiFi connection management with automatic retry and reconnection handling

---

##  Project Structure

```sh
└── weather-monitoring-system/
    ├── Weather.ino
    ├── README.md
    └── circuit-diagrams/
        ├── web-interface-screenshot.png
        └── thingspeak-dashboard.png
```

###  Project Index
<details open>
<summary><b><code>WEATHER-MONITORING-SYSTEM/</code></b></summary>
<details> <!-- __root__ Submodule -->
<summary><b>__root__</b></summary>
<blockquote>
<table>
<tr>
<td><b><a href='https://github.com/vipu18/Weather-Monitoring-System/blob/master/Weather.ino'>Weather.ino</a></b></td>
<td><code>❯ Main Arduino sketch with ESP8266 WiFi setup, DHT sensor integration, rain sensor reading, web server implementation, and ThingSpeak data upload functionality</code></td>
</tr>
<tr>
<td><b><a href='https://github.com/vipu18/Weather-Monitoring-System/blob/master/README.md'>README.md</a></b></td>
<td><code>❯ Comprehensive project documentation including component specifications, circuit diagrams, installation instructions, and usage guidelines</code></td>
</tr>
<tr>
<td><b><a href='https://github.com/vipu18/Weather-Monitoring-System/tree/master/circuit-diagrams'>circuit-diagrams/</a></b></td>
<td><code>❯ Visual documentation including web interface screenshots and ThingSpeak dashboard examples for system demonstration</code></td>
</tr>
</table>
</blockquote>
</details>
</details>

---
##  Getting Started

###  Prerequisites

Before getting started with weather-monitoring-system, ensure your development environment meets the following requirements:

- **Development Environment:** Arduino IDE 1.8.0 or newer with ESP8266 board package
- **Microcontroller Hardware:** ESP8266 development board (NodeMCU, Wemos D1 Mini, or equivalent)
- **Sensor Components:** DHT11/DHT22 temperature-humidity sensor, rain sensor module, connecting jumper wires
- **Network Infrastructure:** Stable WiFi network with internet connectivity for ThingSpeak integration
- **Cloud Platform:** Active ThingSpeak account with API key for data logging and visualization

###  Installation

Install weather-monitoring-system using the following comprehensive setup process:

**Hardware Assembly:**

1. Connect DHT sensor to ESP8266:
```sh
❯ DHT VCC → ESP8266 3.3V (Power Supply)
❯ DHT GND → ESP8266 GND (Ground Connection)
❯ DHT Data → GPIO2 (D4 pin on NodeMCU for data communication)
```

2. Connect rain sensor module:
```sh
❯ Rain Sensor AO → ESP8266 A0 (Analog input for rain intensity)
❯ Rain Sensor VCC → ESP8266 3.3V (Power supply)
❯ Rain Sensor GND → ESP8266 GND (Ground connection)
```

**Software Configuration:**

3. Install Arduino IDE and add ESP8266 support:
```sh
❯ File → Preferences → Additional Board Manager URLs
❯ Add: http://arduino.esp8266.com/stable/package_esp8266com_index.json
❯ Tools → Board → Boards Manager → Search "ESP8266" → Install
```

4. Install required libraries through Library Manager:
```sh
❯ ESP8266WiFi (included with ESP8266 board package)
❯ ESP8266WebServer (included with ESP8266 board package)
❯ DHT sensor library (by Adafruit)
```

5. Clone repository and configure credentials:
```sh
❯ git clone https://github.com/vipu18/Weather-Monitoring-System
❯ Open Weather.ino in Arduino IDE
❯ Update WiFi credentials and ThingSpeak API key
```

###  Usage

Deploy weather-monitoring-system using the following operational workflow:

**System Deployment:**

1. Configure network and cloud credentials in Weather.ino:
```cpp
const char* ssid = "your_wifi_name";
const char* password = "your_wifi_password";
const String apiKey = "your_thingspeak_api_key";
```

2. Upload code to ESP8266:
```sh
❯ Tools → Board → NodeMCU 1.0 (ESP-12E Module)
❯ Tools → Port → Select appropriate COM port
❯ Sketch → Upload (Ctrl+U)
```

**Monitoring and Data Access:**

3. Monitor system status through Serial Monitor:
```sh
❯ Tools → Serial Monitor (115200 baud rate)
❯ Observe WiFi connection status and IP address assignment
❯ Verify sensor reading accuracy and ThingSpeak upload confirmation
```

4. Access local web interface for real-time data:
```sh
❯ Open web browser and navigate to ESP8266's assigned IP address
❯ View current temperature, humidity, pressure, and rainfall readings
❯ Monitor system uptime and connection status
```

5. Remote monitoring via ThingSpeak dashboard:
```sh
❯ Login to ThingSpeak account and access your channel
❯ View historical data charts and real-time sensor readings
❯ Configure alerts and data export options for analysis
```

###  Testing

Validate weather-monitoring-system functionality using comprehensive testing procedures:

**Hardware Validation:**
```sh
❯ # Verify sensor connections with multimeter continuity testing
❯ # Test DHT sensor response by applying controlled temperature/humidity changes
❯ # Validate rain sensor functionality with controlled water application
❯ # Monitor power consumption for battery operation planning
```

**Software and Network Testing:**
- Verify WiFi connection stability over extended operation periods
- Test local web server response and data accuracy through browser access
- Confirm ThingSpeak data upload consistency and field mapping accuracy
- Validate error handling during network disconnection and reconnection scenarios

**Data Quality and Performance Testing:**
- Compare sensor readings with calibrated reference instruments for accuracy validation
- Monitor system performance over 24-48 hour continuous operation cycles
- Test data transmission reliability under varying network conditions

---
##  Project Roadmap

- [X] **`Core Environmental Monitoring`**: <strike>Implement DHT sensor integration for temperature and humidity measurement</strike>
- [X] **`Rain Detection System`**: <strike>Add analog rain sensor support with intensity-based monitoring</strike>
- [X] **`WiFi Connectivity Framework`**: <strike>Enable wireless network connection with automatic reconnection handling</strike>
- [X] **`Local Web Server Interface`**: <strike>Create HTTP server for real-time data display and system status</strike>
- [X] **`ThingSpeak Cloud Integration`**: <strike>Implement automated data upload with structured field mapping</strike>
- [ ] **`Advanced Sensor Suite`**: Add barometric pressure, wind speed/direction, UV index, and soil moisture sensors
- [ ] **`Data Analytics Dashboard`**: Develop comprehensive web-based analytics with historical trends and forecasting
- [ ] **`Mobile Application`**: Create companion iOS/Android app for remote monitoring and alert management
- [ ] **`Multi-Station Network`**: Enable deployment of multiple weather stations with centralized data aggregation
- [ ] **`Machine Learning Integration`**: Implement predictive weather modeling based on historical sensor data

---

##  Contributing

- **💬 [Join the Discussions](https://github.com/vipu18/Weather-Monitoring-System/discussions)**: Share your insights, provide feedback, or ask questions.
- **🐛 [Report Issues](https://github.com/vipu18/Weather-Monitoring-System/issues)**: Submit bugs found or log feature requests for the `weather-monitoring-system` project.
- **💡 [Submit Pull Requests](https://github.com/vipu18/Weather-Monitoring-System/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.

<details closed>
<summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your github account.
2. **Clone Locally**: Clone the forked repository to your local machine using a git client.
   ```sh
   git clone https://github.com/vipu18/Weather-Monitoring-System
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b sensor-enhancement-x
   ```
4. **Make Your Changes**: Develop and test your changes with actual hardware components.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Added barometric pressure sensor integration with BMP280.'
   ```
6. **Push to github**: Push the changes to your forked repository.
   ```sh
   git push origin sensor-enhancement-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.
8. **Review**: Once your PR is reviewed and approved, it will be merged into the main branch. Congratulations on your contribution!
</details>

<details closed>
<summary>Contributor Graph</summary>
<br>
<p align="left">
   <a href="https://github.com/vipu18/Weather-Monitoring-System/graphs/contributors">
      <img src="https://contrib.rocks/image?repo=vipu18/Weather-Monitoring-System">
   </a>
</p>
</details>

---

##  License

This project is protected under the [MIT License](https://choosealicense.com/licenses/mit/) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/mit/) file.

---

##  Acknowledgments

- **Espressif Systems**: For developing the ESP8266 microcontroller platform with comprehensive WiFi integration
- **ThingSpeak by MathWorks**: For providing robust IoT cloud platform with excellent API documentation and data visualization tools
- **Adafruit Industries**: For creating reliable DHT sensor libraries and comprehensive Arduino ecosystem support
- **Arduino Community**: For maintaining the open-source development platform and extensive hardware compatibility
- **Vipanshu Suman**: Project author and maintainer responsible for system design and implementation
- **Open Source IoT Community**: For sharing knowledge and best practices in environmental monitoring solutions
