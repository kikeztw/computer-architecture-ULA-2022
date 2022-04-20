#include "FullAdder.h"
using namespace std;

FullAdder::FullAdder(sc_module_name nm):sc_module(nm){
  SC_METHOD(operation);
  sensitive<< sInA << sInB << sInC;
}

void FullAdder::operation(){
  /*
      Al principio declare en el FullAdder.h las tres variables xOr0, and0, and1
      pero al empezar correr el programa me daba mal los calculos ejemplo: 

      // primeva vuelta
      sInA: 0
      sInB: 0
      sInC: 0
      xOr0: 0

      // segunda vuelta
      sInA: 0
      sInB: 1
      sInC: 0
      xOr0: 0  <--- daba 0 cuando deberia dar uno ya que sInA y sInB pasan por una puerta XOR ( xOr0 )
      temp: 0

      la unica forma de hacer que funcione fue usando bool

  */
  bool xOr0 = sInA.read() != sInB.read();
  bool and0 = sInA.read() && sInB.read();
  bool and1 = sInC.read() && xOr0;
  sOutS.write(xOr0 != sInC.read());
  sOutC.write(and0 || and1);
}