#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char *ssid = "TP-Link_6966";
const char *password = "87506358";

EspSoftwareSerial::UART swSerial;

void setup() {
  Serial.begin(9600);
  swSerial.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, 0, 2);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);

  Serial.print("Connecting to WiFi...");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int Rssi = WiFi.RSSI();
  // Serial.print("RSSI : ");
  Serial.println(Rssi);
  swSerial.println(Rssi);
  delay(100);
}
