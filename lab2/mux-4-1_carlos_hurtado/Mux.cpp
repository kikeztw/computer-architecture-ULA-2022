#include "Mux.h"


Mux::Mux(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << s0In;
  sensitive << s1In;
  sensitive << d0In;
  sensitive << d1In;
  sensitive << d2In;
  sensitive << d3In;
}

void Mux::operation() {
  bool a = !s1In.read() && !s0In.read() &&  d0In.read();
  bool b = !s1In.read() &&  s0In.read() &&  d1In.read();
  bool c =  s1In.read() && !s0In.read() &&  d2In.read();
  bool d =  s1In.read() &&  s0In.read() &&  d3In.read();
  fOut.write(a || b || c || d);
}

Mux::~Mux() {}
