#include <WiFi.h>
#include <WebServer.h>
#include <ElegantOTA.h>

#define ssid "HITRON93394"
#define pass "4D94BHITRON" 

WebServer server(80);

void conectar(){
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(250);
  }
  Serial.println("WiFi Conectado!");
}

char * obtenerInfo() {
  char * message = (char*) malloc(84);
  sprintf(message, "\nSSID: %s\nMAC: %s", ssid, WiFi.macAddress().c_str());
  return message;
}

void setup(){
  Serial.begin(9600);
  conectar();

  ElegantOTA.begin(&server);
  server.begin();

  server.on("/", []() {
    server.send(200, "text/plain", "Hi! This is ElegantOTA Demo.");
  });
}

void loop(){
  server.handleClient();
  ElegantOTA.loop();

  char * info = obtenerInfo();
  Serial.printf("%s\n", info);
  free(info);
  delay(1000);
}
