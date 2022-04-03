#ifndef MUX_H
#define MUX_H

#include <iostream>

#include <systemc.h>


class Mux: public sc_module {
public:
  // inputs signal control
  sc_in<bool> s0In, s1In;
  // inputs data
  sc_in<bool> d0In, d1In, d2In, d3In;
  sc_out<bool> fOut;

  SC_CTOR(Mux);
  ~Mux();

private:
  void operation();
};

#endif