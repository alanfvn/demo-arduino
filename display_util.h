#ifdef ESP32

#ifndef display_util_h
#define display_util_h 

class Pantalla {

  private:

  public:
    Pantalla();
    void iniciar();
    void limpiar();
    void imprimir(int x, int y, char* string);
};

#endif

#endif
