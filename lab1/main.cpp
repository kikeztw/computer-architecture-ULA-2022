#include <iostream>
#include "Testbench.h"
#include "NOTTest.h"
#include "AndGate.h"
#include "OrGate.h"
#include "XorGate.h"
#include "NORGate.h"
#include "NANDGate.h"
#include "XNORGate.h"
#include "NOTGate.h"

using std::cout;
using std::endl;

int sc_main(int argc, char* argv[]) {
  /*
      WARNING: Para ver el resto de las compuertas ir descomenando la que se quiere ver.
      solo mantener una descomentada.
  */

  cout << "Por Defecto esta descomentada la compuerta OR para ver el resto ir al archivo main.cpp y descomentar" << endl << endl;;

  sc_time PERIOD(10, SC_NS); //SC_PS SC_SEC . . .
  sc_time DELAY(10, SC_NS);
  sc_clock clock("clock", PERIOD, 0.5, DELAY, true); // creamos el reloj


  sc_signal<bool> aSg, bSg, cSg; 



  // -------------- AND gate -------------------------

  // AndGate ag1("ag1");
  // Testbench tb("tb");
  // tb.setGateName("AND");


  // ag1.aIn(aSg);
  // ag1.bIn(bSg);
  // ag1.cOut(cSg); 

  // tb.aOut(aSg); 
  // tb.bOut(bSg);
  // tb.cIn(cSg); 

  // tb.clkIn(clock);


  // -------------- OR gate ---------------------------

  OrGate og1("og1");
  Testbench tb("tb");
  tb.setGateName("OR");


  og1.aIn(aSg);
  og1.bIn(bSg);
  og1.cOut(cSg);

  tb.aOut(aSg);
  tb.bOut(bSg);
  tb.cIn(cSg);

  tb.clkIn(clock);

  // -------------- XOR gate ---------------------------

  // XorGate xorg("xorg");
  // Testbench tb("tb");
  // tb.setGateName("XOR");

  // xorg.aIn(aSg);
  // xorg.bIn(bSg);
  // xorg.cOut(cSg);

  // tb.aOut(aSg);
  // tb.bOut(bSg);
  // tb.cIn(cSg);

  // tb.clkIn(clock);

 // -------------- NOR gate ---------------------------

  // NORGate xorg("norg");
  // Testbench tb("tb");
  // tb.setGateName("NOR");

  // xorg.aIn(aSg);
  // xorg.bIn(bSg);
  // xorg.cOut(cSg);

  // tb.aOut(aSg);
  // tb.bOut(bSg);
  // tb.cIn(cSg);

  // tb.clkIn(clock);


 // -------------- NAND gate ---------------------------

  // NANDGate nandg("nandg");
  // Testbench tb("tb");
  // tb.setGateName("NAND");

  // nandg.aIn(aSg);
  // nandg.bIn(bSg);
  // nandg.cOut(cSg);

  // tb.aOut(aSg);
  // tb.bOut(bSg);
  // tb.cIn(cSg);

  // tb.clkIn(clock);

// ------------- XNOR Gate ----------------------------

  // XNORGate xnorg("xnorg");
  // Testbench tb("tb");
  // tb.setGateName("XNORD");

  // xnorg.aIn(aSg);
  // xnorg.bIn(bSg);
  // xnorg.cOut(cSg);

  // tb.aOut(aSg);
  // tb.bOut(bSg);
  // tb.cIn(cSg);

  // tb.clkIn(clock);

// -------------- NOT gate ---------------------------

  // NOTGate notg("notg");
  // NOTTest notTest("notTest");

  // notg.aIn(aSg);
  // notg.cOut(cSg);

  // notTest.aOut(aSg);
  // notTest.cIn(cSg);

  // notTest.clkIn(clock);

  sc_start();
  return 0;
}
