#include <Arduino.h>
#include "WiFi.h"

 
const char* ssid = "DevOps";
const char* password =  "CMJGMww8I1oVUQwqyB8B";

#define LED 2

void setup() {
 
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
    
  }
 
  Serial.println("Connected to the WiFi network");
  digitalWrite(LED, HIGH); //Led de placa indica que está conectado a wifi
  delay(250);
}
 
 
void loop() {
  // put your main code here, to run repeatedly:
}
