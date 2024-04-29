#include <WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "ESP32_AP";  // Name of the ESP32's Access Point
const char *password = "123456789";  // Password for the Access Point

const int b = 34;

WiFiUDP udp;

const int udpPort = 12345;

void setup() {
  Serial.begin(115200);
  
  pinMode(b, INPUT);
  delay(1000);

  // Set up the ESP32 as an Access Point
  WiFi.softAP(ssid, password);
  IPAddress ipAddress = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(ipAddress);

  udp.begin(udpPort);
}

void loop() {
  if(!digitalRead(b)){
    String message = "Button LOW";
    udp.beginPacket("192.168.4.2", udpPort); // Send to connected clients
    udp.print(message);
    udp.endPacket();
    Serial.println("Packet sent: " + message);
  }
}
