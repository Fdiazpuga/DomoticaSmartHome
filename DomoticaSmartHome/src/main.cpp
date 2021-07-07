#include <Arduino.h>
#include "WiFi.h"


#define LED 2

//const char* ssid = "DevOps";
//const char* password =  "CMJGMww8I1oVUQwqyB8B";
const char* ssid = "Chocochino";
const char* password =  "17156mscd";


const int relay1 = 25;
const int relay2 = 26;

void setup() {
 
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

// Configuración del WiFi

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
  digitalWrite(relay1, LOW);
  Serial.println("Relé 1 Encendido");
  delay(60000);

  digitalWrite(relay2, LOW);
  Serial.println("Relé 2 Encendido");
  delay(60000);  

  // Normally Open configuration, send LOW signal to let current flow
  // (if you're usong Normally Closed configuration send HIGH signal)
  digitalWrite(relay1, HIGH);
  Serial.println("Relé 1 Apagado");
  delay(60000);

  digitalWrite(relay2, HIGH);
  Serial.println("Relé 1 Apagado");
  delay(60000); 
}
