#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in<bool> clkIn;
  sc_in<bool> d0In, d1In, d2In, d3In, d4In, d5In, d6In, d7In;
  sc_out<bool> s0Out, s1Out, s2Out;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif