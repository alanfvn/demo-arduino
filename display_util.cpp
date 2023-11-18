#ifdef ESP32

#include "display_util.h"
#include "SH1106Wire.h"

//SDA 0, SCL 4
SH1106Wire display(0x3c, 0, 4);

Pantalla::Pantalla() {}

void Pantalla::iniciar() {
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void Pantalla::imprimir(int x, int y, char* message) {
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(x, y, message);
  display.display();
}

void Pantalla::limpiar() {
  display.clear();
}

#endif
