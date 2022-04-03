#ifndef DECODER_H
#define DECODER_H

#include <iostream>

#include <systemc.h>


class Decoder: public sc_module {
public:
  // inputs
  sc_in<bool> s0In, s1In, s2In;
  // outputs
  sc_out<bool> d0Out;
  sc_out<bool> d1Out;
  sc_out<bool> d2Out;
  sc_out<bool> d3Out;
  sc_out<bool> d4Out;
  sc_out<bool> d5Out;
  sc_out<bool> d6Out;
  sc_out<bool> d7Out;


  SC_CTOR(Decoder);
  ~Decoder();

private:
  void operation();
};

#endif