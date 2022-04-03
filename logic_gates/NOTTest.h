#ifndef NOT_TEST_H
#define NOT_TEST_H

#include <systemc.h>

class NOTTest : public sc_module {
  public:
    sc_in<bool> cIn;
    sc_out<bool> aOut;
    sc_in<bool> clkIn; //El NOTTest siempre deberá tener ésta entrada para el reloj.

    // Construtor del módulo NOTTest
    SC_CTOR(NOTTest);
    ~NOTTest();
  private:
    void print();
    void test();
};

#endif