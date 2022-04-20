#ifndef XNOR_GATE_H
#define XNOR_GATE_H

#include <systemc.h>

// Declaracion del modulo "class AndGate" y heredamos de sc_module
class XNORGate : public sc_module {
  public:
    sc_in<bool> aIn;   //puerto de entrada del modulo
    sc_in<bool> bIn;   //puerta de entrada del modulo
    sc_out<bool> cOut; //puerto de salida del modulo

    // Constructor de un módulo de SystemC. Siempre se debe usar SC_CTOR.
    SC_CTOR(XNORGate);
    ~XNORGate(); //Destructor
  private:
    void operation();
};

#endif