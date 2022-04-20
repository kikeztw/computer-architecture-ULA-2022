#include "NORGate.h"

NORGate::NORGate(sc_module_name moduleName) : sc_module(moduleName) {
  SC_METHOD(operation); // este es el proceso (operacion)
  sensitive << aIn << bIn; // quiere decir que 'operation' se activará con el cambio de aIn o bIn.
}

NORGate::~NORGate() {}

void NORGate::operation() {
  // .write() escribe valores sobre los puertos de salida o entrada-salida
  // .read() lee valores de cualquier puerto
  cOut.write(!(aIn.read() || bIn.read()));
}
