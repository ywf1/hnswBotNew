#include <WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "ESP32_AP";  // Name of the ESP32's Access Point
const char *password = "123456789";  // Password for the Access Point

const int b = 34;
volatile uint
WiFiUDP udp;

const int udpPort = 12345;

void setup() {
  Serial.begin(115200);
  
  adcAttachPin(b);
  delay(1000);

  // Set up the ESP32 as an Access Point
  WiFi.softAP(ssid, password);
  IPAddress ipAddress = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(ipAddress);

  udp.begin(udpPort);
}

void loop() {
  uint16_t adc = analogRead(b);
  udp.beginPacket("192.168.4.2", udpPort); // Send to pc
  udp.print(adc);
  udp.endPacket();
}
