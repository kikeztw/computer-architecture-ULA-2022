#ifndef DECODER_H
#define DECODER_H

#include <iostream>

#include <systemc.h>

#include "AndGate.h"
#include "NotGate.h"


class Decoder: public sc_module{
public:
  sc_in<bool> s0In, s1In, s2In;
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
  AndGate *and0, *and1, *and2, *and3, *and4, *and5, *and6, *and7;
  NotGate *not0, *not1, *not2;
  sc_signal<bool> sgA, sgB, sgC;
};

#endif