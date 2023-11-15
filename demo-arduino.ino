#include <WiFi.h>

#define ssid "HITRON93394"
#define pass "4D94BHITRON" 

void conectar(){
  WiFi.begin(ssid,pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(250);
  }
  Serial.println("WiFi Conectado!");
}

char * obtenerInfo() {
  char * message = (char*) malloc(512);
  strcat(message, "\nSSID: ");
  strcat(message, ssid);
  strcat(message, "\nMAC: ");
  strcat(message, strdup(WiFi.macAddress().c_str()));
  return message;
}

void setup(){
  Serial.begin(9600);
  conectar();
}

void loop(){
  char * info = obtenerInfo();
  Serial.printf("%s\n", info);
  free(info);
  delay(1000);
}
