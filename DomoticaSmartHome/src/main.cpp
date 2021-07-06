#include <Arduino.h>
#include "WiFi.h"


#define LED 2

const char* ssid = "DevOps";
const char* password =  "CMJGMww8I1oVUQwqyB8B";

const int relay = 26;

void setup() {
 
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(relay, OUTPUT);

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
  // Normally Open configuration, send LOW signal to let current flow
  // (if you're usong Normally Closed configuration send HIGH signal)
  digitalWrite(relay, LOW);
  Serial.println("Current Flowing");
  delay(5000); 

  // Normally Open configuration, send LOW signal to let current flow
  // (if you're usong Normally Closed configuration send HIGH signal)
  digitalWrite(relay, HIGH);
  Serial.println("Current Not Flowing");
  delay(5000); 
}
