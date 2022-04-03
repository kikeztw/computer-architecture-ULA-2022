#ifndef ORGATE_H
#define ORGATE_H

#include <systemc.h>


class OrGate : public sc_module {
public:
  sc_in<bool> aIn, bIn, cIn, dIn;
  sc_out<bool> cOut;

  SC_CTOR(OrGate);

private:
  void operation();
};

#endif