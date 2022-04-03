#ifndef MUX_H
#define MUX_H

#include <iostream>

#include <systemc.h>

#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"


class Mux: public sc_module {
public:
  // senial de control
  sc_in<bool> s0In, s1In;
  // entradas
  sc_in<bool> d0In, d1In, d2In, d3In;
  // salidas
  sc_out<bool> fOut;

  SC_CTOR(Mux);
  ~Mux();

private:
/* Para ésta 3era práctica, usaremos compuertas y las usaremos
  creando punteros. */
  AndGate *and0, *and1, *and2, *and3;
  OrGate *or0;
  NotGate *not0, *not1;
  
  // Necesitaremos cables para conecar las compuertas entre sí
  sc_signal<bool> s0Nc, s1Nc, andOut1, andOut2, andOut3, andOut4;
};

#endif
