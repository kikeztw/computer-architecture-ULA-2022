#include "FiveBitsAdder.h"

FiveBitsAdder::FiveBitsAdder(sc_module_name nm) :sc_module(nm) {
  sc_signal<bool> sC0, sC1, sC2, sC3;

  // Usando el fullAdder ( sumador completo de 2 bit con bit de acarreo ) conecto la salida del acarreo
  // del primero sumador con la del segundo y asi hasta conectar los 5 sumadores completos para construir el sumador
  // de 5 bits. Como mencione por razones de tiempo tomando en cuenta el examen del viernes, cortes de luz y trabajo y las otras materias
  // no pude implementar este sumador en su totalidad 

  sc0 = new FullAdder("sc0");
  sc1 = new FullAdder("sc1");
  sc2 = new FullAdder("sc2");
  sc3 = new FullAdder("sc3");
  sc4 = new FullAdder("sc3");
  
  sc0->sInA(sInA[0]);
  sc0->sInB(sInB[0]);
  sc0->sOutC(sC0);

  sc1->sInA(sInA[1]);
  sc1->sInB(sInB[1]);
  sc1->sOutC(sC1);

  sc2->sInA(sInA[2]);
  sc2->sInB(sInB[2]);
  sc2->sOutC(sC2);

  sc3->sInA(sInA[3]);
  sc3->sInB(sInB[3]);
  sc3->sOutC(sC3);

  sc4->sInA(sInA[4]);
  sc4->sInB(sInB[4]);
  sc4->sInC(of);
  // sensitive<< sInA << sInB << sInC;
  // sc0->sInA(sA);
}

