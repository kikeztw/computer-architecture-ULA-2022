#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class Testbench : public sc_module {
public:
  // clock
	sc_in<bool> clkIn;

  // input
  sc_in<bool> fIn;

  // output signal control
	sc_out<bool> s0Out, s1Out;
  // output data
  sc_out<bool>  d0Out, d1Out, d2Out, d3Out;

	SC_CTOR(Testbench);

private:
	void print();
	void test();
};

#endif