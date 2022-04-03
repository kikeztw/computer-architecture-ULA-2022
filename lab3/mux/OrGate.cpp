#include "OrGate.h"


OrGate::OrGate(sc_module_name mn) : sc_module(mn) {
  SC_METHOD(operation);
  sensitive << aIn;
  sensitive << bIn;
  sensitive << cIn;
  sensitive << dIn;
}

void OrGate::operation() {
  cOut.write(aIn.read() or bIn.read() or cIn.read() or dIn.read());
}