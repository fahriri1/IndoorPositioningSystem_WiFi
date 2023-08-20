#include <SoftwareSerial.h>

#define D5 (14)
#define D6 (12)
#define D7 (13)
#define D4 (2)

EspSoftwareSerial::UART swSerial1;
EspSoftwareSerial::UART swSerial2;
EspSoftwareSerial::UART swSerial3;

int Rssi[3];

void setup() {
  Serial.begin(9600);

  swSerial1.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, D6, D4);
  swSerial2.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, D7, D8);
  swSerial3.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, D5, D4);
}

void loop() {
  String buffer;

  //Dapatkan koordinat Rssi 1
  if(swSerial1.available()){
    buffer = swSerial1.readString();
    Serial.println(buffer);
    Rssi[0] = buffer.toInt();
  }

  //Dapatkan koordinat Rssi 2
  if(swSerial2.available()){
    buffer = swSerial2.readString();
    Serial.println(buffer);
    Rssi[1] = buffer.toInt();
  }

  //Dapatkan koordinat Rssi 3
  if(swSerial3.available()){
    buffer = swSerial3.readString();
    Serial.println(buffer);
    Rssi[1] = buffer.toInt();
  }

  //Print koordinat
  Serial.print("Koordinat : (");
  Serial.print(Rssi[0]);
  Serial.print(",");
  Serial.print(Rssi[1]);
  Serial.print(",");
  Serial.print(Rssi[2]);
  Serial.println(")");

  delay(100);
}