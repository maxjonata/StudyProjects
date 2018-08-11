/*
Arduino Due - ESP 8266 WiFi Module
Serial (Tx/Rx) communicate to PC via USB
Serial3 (Tx3/Rx3) connect to ESP8266
Tx3 - ESP8266 Rx
Rx3 - ESP8266 Tx
pin 53 - ESP8266 CH_PD (Always High)
*/

#define ESP8266 Serial3

int LED = 13;

//always high
int CH_PD_8266 = 53;

boolean FAIL_8266 = false;

void setup() {
    Serial.begin(74880);
    ESP8266.begin(74880);
}

void loop() {

}
