#include "wifi_util.h"

void connectWiFi(
  const char* ssid, const char* pass, 
  void (*onConnecting)(), void (*onConnected)() 
){
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    onConnecting(); delay(250);
  }
  onConnected();
}
