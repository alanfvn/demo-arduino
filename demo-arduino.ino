#include <WebServer.h>
#include <ElegantOTA.h>

#include "my_constants.h"
#include "my_functions.h"
#include "wifi_util.h"

WebServer server(80);

//callbacks
void onWiFiConnecting(){
  Serial.print(".");
}

void onWiFiConnected(){
  Serial.println("Conectado!");
}

void setup(){
  //setup serial
  Serial.begin(9600);

  connectWiFi(SSID, PASS, onWiFiConnecting, onWiFiConnected);

  ElegantOTA.begin(&server);
  server.begin();
  server.on("/", []() { server.send(200, "text/plain", "Hola has accedido al ESP32!"); });
}

void loop(){
  server.handleClient();
  ElegantOTA.loop();

  Serial.println("Test@!");

  // char * info = obtenerInfo();
  // Serial.printf("%s\n", info);
  // free(info);
  delay(1000);
}
