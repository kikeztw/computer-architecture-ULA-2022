// Carlos Enrique Hurtado Puente
// 22929504
// Por Rezones de tiempo y tomando en cuenta que el examen es el viernes, los cortes de luz y el trabajo
// solo pude implementar un sumador completo de dos bits con su testbench que es el ejemplo 
// que se encuentra en el main. Para el sumador de 5bits solo lo implemente en una parte en el archivo
// FiveBitsAdder.
#include "FullAdder.h"
#include "FullAdderTestbench.h"

using namespace std;

int sc_main(int argv, char* argc[]) {

  cout<<"----------- WARNING:"<<endl;
  cout<<"Por Rezones de tiempo y tomando en cuenta que el examen es el viernes, los cortes de luz y el trabajo"<<endl;
  cout<<"solo pude implementar un sumador completo de dos bits con su testbench que es el ejemplo  que se encuentra en el main"<<endl;
  cout<<"Para el sumador de 5bits solo lo implemente en una parte en el archivo FiveBitsAdder."<<endl<<endl;

	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);	
	sc_clock clock("clock", period, 0.5, delay, true);

  FullAdder sc("fat");
  FullAdderTestbench tb("fatb");

  sc_signal<bool> sA, sB, sC, sigS, sigC;

  sc.sInA(sA);
  sc.sInB(sB);
  sc.sInC(sC);

  sc.sOutS(sigS);
  sc.sOutC(sigC);

  tb.sIn(sigS);
  tb.sInC(sigC);

  tb.sOutA(sA);
  tb.sOutB(sB);
  tb.sOutC(sC);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
