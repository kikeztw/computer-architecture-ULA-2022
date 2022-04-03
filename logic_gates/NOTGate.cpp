#include "NOTGate.h"

// using std::cout;

NOTGate::NOTGate(sc_module_name moduleName) : sc_module(moduleName) {
  SC_METHOD(operation); // este es el proceso (operacion)
  sensitive << aIn; // quiere decir que 'operation' se activará con el cambio de aIn o bIn.
}

NOTGate::~NOTGate() {}

void NOTGate::operation() {
  // Acá se ejecuta la operación del módulo
  // .write() escribe valores sobre los puertos de salida o entrada-salida
  // .read() lee valores de cualquier puerto
  // cout << "Test before" << aIn.read() << "\n";
  // cout << "Test after" << !aIn.read() << "\n";

  cOut.write(!aIn.read());
}


