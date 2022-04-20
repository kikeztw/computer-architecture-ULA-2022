#ifndef FIVEBITSADDER_H
#define FIVEBITSADDER_H

#include <iostream>
#include <systemc.h>
#include "FullAdder.h"

class FiveBitsAdder: public sc_module{
  public:
    sc_in<bool> sInA[5], sInB[5], of;
    sc_out<bool> sOut[5];


    SC_CTOR(FiveBitsAdder);

  private:
    FullAdder *sc0, *sc1, *sc2, *sc3, *sc4;
    
};
#endif