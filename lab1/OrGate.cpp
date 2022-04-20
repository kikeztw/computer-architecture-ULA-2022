#include "OrGate.h"

OrGate::OrGate(sc_module_name moduleName) : sc_module(moduleName) {
  SC_METHOD(operation); // este es el proceso (operacion)
  sensitive << aIn << bIn; // quiere decir que 'operation' se activará con el cambio de aIn o bIn.
}

OrGate::~OrGate() {}

void OrGate::operation() {
  // Acá se ejecuta la operación del módulo
  // .write() escribe valores sobre los puertos de salida o entrada-salida
  // .read() lee valores de cualquier puerto
  cOut.write(aIn.read() || bIn.read());
  // Se ejecuta la operacion logica 'and' entre los valores de aIn y bIn.
}