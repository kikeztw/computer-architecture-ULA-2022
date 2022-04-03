#include "Decoder.h"


Decoder::Decoder(sc_module_name nm):sc_module(nm) {
  SC_METHOD(operation);
  sensitive << s0In;
  sensitive << s1In;
  sensitive << s2In;
}

/**
 * La operación que realiza el decoder es básicamente "habilitar" una de entre todas
 * las salidas según la entrada. La entrada pueden verla como un número binario compuesto
 * por n bits, en éste caso n = 1. Ese número en binario "habilitará" una de las 2^n salidas
 * y la salida "habilitada" tendrá un valor de 1 mientras que el resto de salidas tendrán un 0.
 * Por ejemplo, si la entrada es 0, la salida 0 tendrá un valor de 1 y la salida 1 tendrá un 0.
 * Y si la entrada es 1, la salida 0 tendrá un 0 y la salida 1 tendrá un 1.
 */
void Decoder::operation() {
  d0Out.write(!s0In.read() && !s1In.read() && !s2In.read());
  d1Out.write(s0In.read() && !s1In.read() && !s2In.read());
  d2Out.write(!s0In.read() && s1In.read() && !s2In.read());
  d3Out.write(s0In.read() && s1In.read() && !s2In.read());
  d4Out.write(!s0In.read() && !s1In.read() && s2In.read());
  d5Out.write(s0In.read() && !s1In.read() && s2In.read());
  d6Out.write(!s0In.read() && s1In.read() && s2In.read());
  d7Out.write(s0In.read() && s1In.read() && s2In.read());
}

Decoder::~Decoder() {}