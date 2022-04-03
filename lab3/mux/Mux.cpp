#include "Mux.h"
#include <iostream>

Mux::Mux(sc_module_name nm) : sc_module(nm) {
  // Hacemos que nuestros punteros apunten a instancias que creamos
  and0 = new AndGate("and0");
  and1 = new AndGate("and1");
  and2 = new AndGate("and2");
  and3 = new AndGate("and3");

  or0 = new OrGate("or0");
  not0 = new NotGate("not0");
  not1 = new NotGate("not1");

  // negaciones
  not0->aIn(s0In);
  not0->bOut(s0Nc);

  not1->aIn(s1In);
  not1->bOut(s1Nc);

  // std::cout << s0In << "\n";
  // and gates
  // A gate 
  and0->aIn(s0Nc);
  and0->bIn(s1Nc);
  and0->cIn(d0In);
  and0->cOut(andOut1);

  // b gate 
  and1->aIn(s0In);
  and1->bIn(s1Nc);
  and1->cIn(d1In);
  and1->cOut(andOut2);

  // c gate 
  and2->aIn(s0Nc);
  and2->bIn(s1In);
  and2->cIn(d2In);
  and2->cOut(andOut3);

  // c gate 
  and3->aIn(s0In);
  and3->bIn(s1In);
  and3->cIn(d3In);
  and3->cOut(andOut4);

  or0->aIn(andOut1);
  or0->bIn(andOut2);
  or0->cIn(andOut3);
  or0->dIn(andOut4);

  or0->cOut(fOut);
}

Mux::~Mux() {
  // Es importante recordar liberar la memoria que asignamos
  delete not0;
  delete and0;
  delete and1;
  delete or0;
}