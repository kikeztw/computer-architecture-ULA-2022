#include <iostream>

#include "NOTTest.h"

using std::cout;
using std::endl;

NOTTest::NOTTest(sc_module_name moduleName) : sc_module(moduleName) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
}

NOTTest::~NOTTest() {}

void NOTTest::print() {
  cout << aOut.read() << " ";
  cout << cIn.read() << endl;
}

void NOTTest::test() {
  cout << " Compuerta NOT" << endl;
  cout << "Input Output" << endl;

  //Se comienzan a enviar los estimulos
  for (int i = 0; i <= 1; ++i) {
    aOut.write(i);
    wait();
    print();
  }
  sc_stop();

  /**
   * write: les mandamos valores 0 o 1 a los puertos de salida del NOTTest
   * (los cuales son los puertos de entrada del módulo a probar)
   *
   * wait: al ejecutar wait, el NOTTest espera hasta que suceda el evento clk.pos()
   * profe, pero por qué clk.pos()?
   * pues porque es lo que definimos con "sensitive<<clk.pos()" y es lo que queremos que suceda
   *
   * print: llama a print() para imprimir los resultados obtenidos antes de enviarle nuevos estimulos y proseguir con la evaluacion del modulo
   * 
   * sc_stop: para el NOTTest
   **/
}