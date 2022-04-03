// Carlos Enrique Hurtado Puente
// 22929504
// decoder de 3x8
#include "Decoder.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10, SC_NS);
  sc_time delay(10, SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  Decoder dec("dec");
  Testbench tb("tb");

  // Necesitaremos cables para conectar los módulos
  sc_signal<bool> s0Sg;
  sc_signal<bool> s1Sg;
  sc_signal<bool> s2Sg;

  sc_signal<bool> d0Sg;
  sc_signal<bool> d1Sg;
  sc_signal<bool> d2Sg;
  sc_signal<bool> d3Sg;
  sc_signal<bool> d4Sg;
  sc_signal<bool> d5Sg;
  sc_signal<bool> d6Sg;
  sc_signal<bool> d7Sg;


  // Decoder output
  dec.s0In(s0Sg);
  dec.s1In(s1Sg);
  dec.s2In(s2Sg);

  // Decoder output
  dec.d0Out(d0Sg);
  dec.d1Out(d1Sg);
  dec.d2Out(d2Sg);
  dec.d3Out(d3Sg);
  dec.d4Out(d4Sg);
  dec.d5Out(d5Sg);
  dec.d6Out(d6Sg);
  dec.d7Out(d7Sg);

  // test betch output
  tb.s0Out(s0Sg);
  tb.s1Out(s1Sg);
  tb.s2Out(s2Sg);

  // test betch input
  tb.d0In(d0Sg);
  tb.d1In(d1Sg);
  tb.d2In(d2Sg);
  tb.d3In(d3Sg);
  tb.d4In(d4Sg);
  tb.d5In(d5Sg);
  tb.d6In(d6Sg);
  tb.d7In(d7Sg);

  // Conectando el reloj al testbench
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();

  return 0;
}
