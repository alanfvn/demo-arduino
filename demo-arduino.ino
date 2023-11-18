#include <WebServer.h>
#include <ElegantOTA.h>

#include "my_constants.h"
#include "my_functions.h"
#include "wifi_util.h"
#include "display_util.h"

WebServer server(80);
Pantalla pantalla;

//callbacks
void onWiFiConnecting(){
  Serial.print(".");
  pantalla.limpiar();
  pantalla.imprimir(0, 0, "Conectando..");
}

void onWiFiConnected(){
  pantalla.limpiar();
  pantalla.imprimir(0, 0, "CONECTADO!");
  Serial.println("Conectado!");
}

void setup(){
  //setup serial
  Serial.begin(9600);
  pantalla.iniciar();
  connectWiFi(SSID, PASS, onWiFiConnecting, onWiFiConnected);

  ElegantOTA.begin(&server);
  server.begin();
  server.on("/", []() { server.send(200, "text/plain", "Hola has accedido al ESP32!"); });
}

void loop(){
  server.handleClient();
  ElegantOTA.loop();

  long echoDur = getPulseDuration();
  int cm = getUltraSonicDistance(echoDur);

  Serial.printf("Duracion: %d", cm);
  delay(1000);
}

long getPulseDuration(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH);
  return duration;
}
