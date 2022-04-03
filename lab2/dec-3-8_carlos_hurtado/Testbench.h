#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
  // clock
  sc_in<bool> clkIn;
  // inpout
  sc_in<bool> d0In;
  sc_in<bool> d1In;
  sc_in<bool> d2In;
  sc_in<bool> d3In;
  sc_in<bool> d4In;
  sc_in<bool> d5In;
  sc_in<bool> d6In;
  sc_in<bool> d7In;

  // output
  sc_out<bool> s0Out;
  sc_out<bool> s1Out;
  sc_out<bool> s2Out;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif