#include "Testbench.h"

int inputs_signals[4][2] = {
  {0, 0},
  {0, 1},
  {1, 0},
  {1, 1}
};

int inputs_data[4][4] = {
  {0, 0, 0, 1},
  {0, 0, 1, 0},
  {0, 1, 0, 0},
  {1, 0, 0, 0}
};

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn.pos();
  dont_initialize();
}

void Testbench::print() {
  std::cout << sc_time_stamp() << "    ";
  // outputs controls signal
  std::cout << s1Out.read() << "    ";
  std::cout << s0Out.read() << "    ";
  // outpust data
  std::cout << d3Out.read() << "    ";
  std::cout << d2Out.read() << "    ";
  std::cout << d1Out.read() << "    ";
  std::cout << d0Out.read() << "    ";

  // input
  std::cout << fIn.read() << "\n";
}

void Testbench::test() {
  std::cout << "Tiempo  s1   s0    d3   d2   d1   d0    f\n";
  std::cout << "-------------------------\n";

  for(int i = 0; i < 4; i++){
    d3Out.write(inputs_data[i][0]);
    d2Out.write(inputs_data[i][1]);
    d1Out.write(inputs_data[i][2]);
    d0Out.write(inputs_data[i][3]);
    s0Out.write(inputs_signals[i][1]);
    s1Out.write(inputs_signals[i][0]);
    wait();
    print();
    std::cout << "-------------------------\n";
  }
  sc_stop();
}