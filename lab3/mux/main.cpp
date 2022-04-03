// Carlos Enrique Hurtado Puente
// 22929504
#include "Mux.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  // Configuración del reloj
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  // Creando el reloj
  sc_clock clock("clock", period, 0.5, delay, true);

  // Creando instancias de los módulos
  Mux mux("mux");
  Testbench tb("tb");

  // Necesitaremos cables para conectar los módulos
  sc_signal<bool> s0Sg, s1Sg, fSg;
  sc_signal<bool> d0Sg, d1Sg, d2Sg, d3Sg;

  // signals
  mux.s0In(s0Sg);
  mux.s1In(s1Sg);
  // input
  mux.d0In(d0Sg);
  mux.d1In(d1Sg);
  mux.d2In(d2Sg);
  mux.d3In(d3Sg);
  // output
  mux.fOut(fSg);

  // input
  tb.fIn(fSg);
  // signals ouput
  tb.s0Out(s0Sg);
  tb.s1Out(s1Sg);
  // output
  tb.d0Out(d0Sg);
  tb.d1Out(d1Sg);
  tb.d2Out(d2Sg);
  tb.d3Out(d3Sg);

  // Conectando el reloj al testbench
  tb.clkIn(clock);

  // Inicializando el simulador
  sc_start();

  return 0;
}
