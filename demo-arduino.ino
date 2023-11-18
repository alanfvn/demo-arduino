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
  char * data = getNetworkInfo(SSID, ".");
  pantalla.limpiar();
  pantalla.imprimir(0, 0, data);
  Serial.println(data);
  free(data);
}

void setup(){
  //setup serial
  pantalla.iniciar();
  Serial.begin(9600);
  connectWiFi(SSID, PASS, onWiFiConnecting, onWiFiConnected);

  ElegantOTA.begin(&server);
  server.begin();
  server.on("/", []() { server.send(200, "text/plain", "Hola has accedido al ESP32!"); });

  //pins
  pinMode(TRIG, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO, INPUT); // Sets the echoPin as an Input
}

void loop(){
  server.handleClient();
  ElegantOTA.loop();

  long echoDur = getPulseDuration();
  int cm = getUltraSonicDistance(echoDur);

  char *data = getUltraSonicString(cm);
  pantalla.limpiar();
  pantalla.imprimir(0,0,data);
  free(data);

  Serial.printf("Duracion: %d\n", cm);
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
