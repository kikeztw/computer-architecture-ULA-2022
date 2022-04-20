#include "FullAdderTestbench.h"

// C, A, B
int input[8][3] = {
  {0, 0, 0 },
  {0, 0, 1 },
  {0, 1, 0 },
  {0, 1, 1 },
  {1, 0, 0 },
  {1, 0, 1 },
  {1, 1, 0 },
  {1, 1, 1 },
};

FullAdderTestbench::FullAdderTestbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void FullAdderTestbench::print(){
  std::cout << sc_time_stamp() << "    ";
  std::cout << sOutC.read() << "    ";
  std::cout << sOutA.read() << "    ";
  std::cout << sOutB.read() << "    |     ";
  std::cout << sInC.read() << "    ";
  std::cout << sIn.read() << "\n";
}

void FullAdderTestbench::test() {
  std::cout << "Tiempo   Ce    A    B    |  Cs   S   \n";
  std::cout << "---------------------\n";

  for(int i=0; i < 8; i++) {
    for(int j=0; j < 3; j++) {
      if(j == 0){
        sOutC.write(input[i][j]);
      }
      if(j == 1){
        sOutA.write(input[i][j]);
      }
      if(j == 2){
        sOutB.write(input[i][j]);
      }
    }
    wait();
    print();
  }

  sc_stop();
}