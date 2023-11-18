#ifdef ESP32

#ifndef WIFI_UTIL_H
#define WIFI_UTIL_H

#include <Arduino.h>
#include <WiFi.h>

void connectWiFi( 
  const char* ssid, const char* pass, 
  void (*onConnecting)(), void (*onConnected)() 
);

#endif // !WIFI_UTIL_H
#endif
