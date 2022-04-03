#include "Testbench.h"

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

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void Testbench::print() {
  std::cout << sc_time_stamp() << "    ";
  // outputs
  std::cout << s2Out.read() << "    ";
  std::cout << s1Out.read() << "    ";
  std::cout << s0Out.read() << "     | ";
  // inputs
  std::cout << d7In.read() << "    ";
  std::cout << d6In.read() << "    ";
  std::cout << d5In.read() << "    ";
  std::cout << d4In.read() << "    ";
  std::cout << d3In.read() << "    ";
  std::cout << d2In.read() << "    ";
  std::cout << d1In.read() << "    ";
  std::cout << d0In.read() << "\n";
}

void Testbench::test() {
  std::cout << "Tiempo   s2   s1   s0    | d7  d6   d5   d4   d3   d2   d1   d0\n";
  std::cout << "---------------------\n";

  for(int i=0; i < 8; i++) {
    for(int j=0; j < 3; j++) {
      if(j == 0){
        s2Out.write(input[i][j]);
      }
      if(j == 1){
        s1Out.write(input[i][j]);
      }
      if(j == 2){
        s0Out.write(input[i][j]);
      }
    }
    wait();
    print();
  }

  sc_stop();
}