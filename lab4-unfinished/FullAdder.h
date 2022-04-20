#ifndef FULLADDER_H
#define FULLADDER_H

#include <iostream>
#include <systemc.h>

class FullAdder: public sc_module {
public: 
  sc_in<bool> sInA, sInB, sInC;
  sc_out<bool> sOutS, sOutC;

  SC_CTOR(FullAdder);

private:
  void operation();
  // sc_signal<bool> xOr0, and0, and1;
};

#endif