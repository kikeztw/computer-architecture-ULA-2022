#include "NANDGate.h"

NANDGate::NANDGate(sc_module_name moduleName) : sc_module(moduleName) {
  SC_METHOD(operation); // este es el proceso (operacion)
  sensitive << aIn << bIn; // quiere decir que 'operation' se activará con el cambio de aIn o bIn.
}

NANDGate::~NANDGate() {}

void NANDGate::operation() {
  cOut.write(!(aIn.read() && bIn.read()));
}
