#include "Decoder.h"


Decoder::Decoder(sc_module_name nm):sc_module(nm) {
  and0 = new AndGate("and0");
  and1 = new AndGate("and1");
  and2 = new AndGate("and2");
  and3 = new AndGate("and3");
  and4 = new AndGate("and4");
  and5 = new AndGate("and5");
  and6 = new AndGate("and6");
  and7 = new AndGate("and7");

  not0 = new NotGate("not0");
  not1 = new NotGate("not1");
  not2 = new NotGate("not2");

  // negaciones
  not0->aIn(s0In);
  not0->bOut(sgA);

  not1->aIn(s1In);
  not1->bOut(sgB);

  not2->aIn(s2In);
  not2->bOut(sgC);

  // salidas

  // D0
  and0->aIn(sgA);
  and0->bIn(sgB);
  and0->cIn(sgC);
  and0->cOut(d0Out);

  // D1
  and1->aIn(s0In);
  and1->bIn(sgB);
  and1->cIn(sgC);
  and1->cOut(d1Out);

  // D2
  and2->aIn(sgA);
  and2->bIn(s1In);
  and2->cIn(sgC);
  and2->cOut(d2Out);

  // D3
  and3->aIn(s0In);
  and3->bIn(s1In);
  and3->cIn(sgC);
  and3->cOut(d3Out);

  // D4
  and4->aIn(sgA);
  and4->bIn(sgB);
  and4->cIn(s2In);
  and4->cOut(d4Out);

  // D5
  and5->aIn(s0In);
  and5->bIn(sgB);
  and5->cIn(s2In);
  and5->cOut(d5Out);

  // D6
  and6->aIn(sgA);
  and6->bIn(s1In);
  and6->cIn(s2In);
  and6->cOut(d6Out);

  // D7
  and7->aIn(s0In);
  and7->bIn(s1In);
  and7->cIn(s2In);
  and7->cOut(d7Out);
}

Decoder::~Decoder() {
  delete and0;
  delete and1;
  delete and2;
  delete and3;
  delete not0;
  delete not1;
}