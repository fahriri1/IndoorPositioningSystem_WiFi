#include <SoftwareSerial.h>

#define D2 (4)
#define D3 (0)
#define D5 (14)
#define D6 (12)
#define D7 (13)

EspSoftwareSerial::UART swSerial1;
EspSoftwareSerial::UART swSerial2;
EspSoftwareSerial::UART swSerial3;
EspSoftwareSerial::UART JetsonSer;

int Rssi[3];

String mode;

void setup() {
  Serial.begin(9600);

  swSerial1.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, D6, D4);
  swSerial2.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, D7, D4);
  swSerial3.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, D5, D4);
  JetsonSer.begin(9600, EspSoftwareSerial::SWSERIAL_8N1, D2, D3);
}

void loop() {
  String buffer;

  //Dapatkan koordinat Rssi 1
  if(swSerial1.available()){
    buffer = swSerial1.readStringUntil('\n');
    // Serial.println(buffer);
    Rssi[0] = buffer.toInt();
  }

  //Dapatkan koordinat Rssi 2
  if(swSerial2.available()){
    buffer = swSerial2.readStringUntil('\n');
    // Serial.println(buffer);
    Rssi[1] = buffer.toInt();
  }

  //Dapatkan koordinat Rssi 3
  if(swSerial3.available()){
    buffer = swSerial3.readStringUntil('\n');
    // Serial.println(buffer);
    Rssi[2] = buffer.toInt();
  }

  if(Serial.available()>0){
    mode = Serial.readStringUntil('#');
    Serial.println(mode);
  }

  while(mode == "RSSI"){
    //Print koordinat
    // Serial.write("-90/-80/-55");
    String mesg = String(Rssi[0]) + String(":") + String(Rssi[1]) + String(":") + String(Rssi[2]) + String("/");
    Serial.println(mesg);

    if(Serial.available()>0){
      String dat = Serial.readStringUntil('#');
      if(dat == "Control"){
        mode = dat;
      }
      Serial.println(dat);
      JetsonSer.println("a/" + dat);
    }
    delay(100);
  }

  while(mode == "Control"){
    if(Serial.available()>0){
      String dat = Serial.readStringUntil('#');
      Serial.println(dat);
      JetsonSer.println("b/" + dat);
      if(dat == "RSSI"){
        mode = dat;
      }
    }
  }
}