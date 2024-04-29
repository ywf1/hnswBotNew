#include <WiFi.h>

const char *ssid = "ESP32_AP";     // SSID (name) of the ESP32 Access Point
const char *password = "password"; // Password of the ESP32 Access Point

WiFiServer server(80); // Create a server on port 80
int analogPin = 34;    // Analog pin to read from

void setup() {
  Serial.begin(115200);

  adcAttachPin(analogPin);
  delay(1000);

  // Set up ESP32 as Access Point
  WiFi.softAP(ssid, password);

  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // Check if a client has connected
  if (client) {
    Serial.println("New Client connected.");
    while (client.connected()) { // Loop while the client is connected
      int sensorValue = analogRead(analogPin); // Read the analog value
      client.println(sensorValue); // Send the analog value to the client
      //delay(); // Delay for stability
    }
    client.stop(); // Close the connection
    Serial.println("Client disconnected.");
  }
}
