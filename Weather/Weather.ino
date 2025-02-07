#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "DHT.h"

// WiFi credentials
const char* ssid = "wifi_name";
const char* password = "wifi_password";

// ThingSpeak API key
const String apiKey = "api_key";

// Define pin numbers
const int rainSensorPin = A0; // AO pin of the rain sensor connected to analog pin A0
#define DHTPIN D4        // Pin to connect DHT sensor (GPIO number) D2
#define DHTTYPE DHT11    // Define DHT 11 or DHT22 sensor type

DHT dht(DHTPIN, DHTTYPE);

ESP8266WebServer server(80);

void handleRoot() {
  // Read the analog value from the rain sensor
  int sensorValue = analogRead(rainSensorPin);

  // Read DHT sensor data
  float temperatureC = dht.readTemperature(false); // Read temperature in Celsius
  float temperatureF = dht.readTemperature(true); // Read temperature in Fahrenheit
  float humidity = dht.readHumidity();             // Read humidity

  String message = "<html><head><title>Weather Station</title></head><body>";
  message += "<h1>Weather Station</h1>";
  message += "<p>Rain Sensor Value: " + String(sensorValue) + "</p>";
  message += "<p>Temperature: " + String(temperatureC) + "°C</p>";
  message += "<p>Temperature: " + String(temperatureF) + "°F</p>";
  message += "<p>Humidity: " + String(humidity) + "%</p>";
  message += "</body></html>";

  server.send(200, "text/html", message);
}

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  delay(1000); // Wait for serial monitor to open

  // Connect to WiFi
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  dht.begin();

  server.on("/", handleRoot);
  server.begin();

  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();

  // Read sensor data
  int sensorValue = analogRead(rainSensorPin);
  float temperatureC = dht.readTemperature(false); // Read temperature in Celsius
  float temperatureF = dht.readTemperature(true); // Read temperature in Fahrenheit
  float humidity = dht.readHumidity();             // Read humidity

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    if (client.connect("api.thingspeak.com", 80)) {
      String postStr = "api_key=" + apiKey;
      postStr += "&field1=" + String(sensorValue);
      postStr += "&field2=" + String(temperatureC);
      postStr += "&field3=" + String(temperatureF);
      postStr += "&field4=" + String(humidity);

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.println("Data sent to ThingSpeak");
    }
    client.stop();
  }

  // Delay before next reading and sending
  delay(10000); // Wait for 10 seconds
}
