Code ini dikhususkan untuk Indoor Positioning System pada c++
==
Perangkat yang digunakan yaitu :
- ESP-01
- ESP-8266

Tanggal : 19/08/2023
--
Tujuan	:
- membuat code untuk mendapatkan data RSSI dari tiga sumber wifi
- membuat code untuk menerima ketiga data RSSI tersebut dan jadikan sebagai koordinat

Psudocode :
1. ESP-01

Serial.begin(9600);
Koneksikan dengan WiFi();

Rssi = ambil rssi wifi;
Serial.print(Rssi+'#');

2. ESP-8266

Serial1.begin(9600);
Serial2.begin(9600);
Serial3.begin(9600);

BacaRssi(){
   Rssi1 = Serial1.readStringUntil('#');
   Rssi1 = jadikan sebagai float;
   Rssi2 = Serial2.readStringUntil('#');
   Rssi2 = jadikan sebagai float;
   Rssi3 = Serial3.readStringUntil('#');
   Rssi3 = jadikan sebagai float;
   IPS = [Rssi1, Rssi2, Rssi3];

Tanggal : 20/08/2023
--
Tujuan :
- Memastikan bahwa data RSSI SATU ESP01 didapatkan melalui UART
- Memastikan bahwa data RSSI DUA ESP01 didapatkan melalui UART
- Membuat desain PCB

Plan A:
- Komunikasi ESP01 ke ESP8266 melalui UART dengan pin UART0
Plan B (works) :
- Komunikasi ESP01 ke ESP8266 melalui UART dengan EspSoftwareSerial
Plan C (works) :
- Komunikasi ESP01 ke Arduino melalui UART
Plan D:
- Komunikasi ESP01 ke ESP8266 melalui FIREBASE

PIN OUT
--
ESP8266    ESP01
3V3        3V3
3V3        EN
GND        GND
D7         TX1
D8         TX2
D9         TX3
