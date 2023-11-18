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
  ElegantOTA.begin(&server);
  server.begin();
  server.on("/", []() { server.send(200, "text/plain", "Hola has accedido al ESP32!"); });

  connectWiFi(SSID, PASS, onWiFiConnecting, onWiFiConnected);
}

void loop(){
  server.handleClient();
  ElegantOTA.loop();
  // char * info = obtenerInfo();
  // Serial.printf("%s\n", info);
  // free(info);
  Serial.println("actualizado!");
  delay(1000);
}
