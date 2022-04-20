#ifndef FULLADDERTESTBENCH_H
#define FULLADDERTESTBENCH_H

#include <iostream>
#include <systemc.h>

class FullAdderTestbench : public sc_module {
public:
  sc_in<bool> clkIn;
  sc_in<bool> sIn, sInC;
  sc_out<bool> sOutA, sOutB,sOutC;

  SC_CTOR(FullAdderTestbench);

private:
  void print();
  void test();
};

#endif


  // sc_in<bool> sIn, sInC;
  // sc_out<bool> sOutA, sOutB,sOutC;