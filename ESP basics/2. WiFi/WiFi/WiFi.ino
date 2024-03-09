/*
Made by MatusRepkaSolutions - ESP-Arduino-Internet-Basics
 
Remember to hold the boot button while uploading your code,
then reset the ESP after it's uploaded.
*/
#include <WiFi.h> //This is a default ArduinoIDE library https://www.arduino.cc/reference/en/libraries/wifi/

//Your WiFi informations
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);// https://www.arduino.cc/reference/en/libraries/wifi/wifi.begin/
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
}

void loop() {
}
