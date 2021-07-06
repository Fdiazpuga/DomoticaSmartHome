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
    //Led de Placa parpadea si no tiene conexión WiFi
    delay(500);
    Serial.println("Connecting to WiFi..");
    digitalWrite(LED, HIGH);
    delay(50);
    digitalWrite(LED, LOW);
    delay(50);
  }
  // Si se conecta a la red, el led de la placa se mantiene encendido durante 5seg luego se apaga
  Serial.println("Connected to the WiFi network");
  digitalWrite(LED, HIGH); 
  delay(5000);
  digitalWrite(LED, LOW);
}
 
 
void loop() {
  // put your main code here, to run repeatedly:
}
