// Carlos Enrique Hurtado Puente
// 22929504
#include "AndGate.h"
#include "NotGate.h"
#include "Testbench.h"
#include "Decoder.h"


int sc_main(int argv, char* argc[]) {
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);	
	sc_clock clock("clock", period, 0.5, delay, true);

	Decoder dec("dec");
	Testbench tb("tb");

	sc_signal<bool> s0Sg, s1Sg, s2Sg;
	sc_signal<bool> d0Sg, d1Sg, d2Sg, d3Sg, d4Sg, d5Sg, d6Sg, d7Sg;

	dec.s0In(s0Sg);
	dec.s1In(s1Sg);
	dec.s2In(s2Sg);

	dec.d0Out(d0Sg);
	dec.d1Out(d1Sg);
	dec.d2Out(d2Sg);
	dec.d3Out(d3Sg);
	dec.d4Out(d4Sg);
	dec.d5Out(d5Sg);
	dec.d6Out(d6Sg);
	dec.d7Out(d7Sg);


	tb.d0In(d0Sg);
	tb.d1In(d1Sg);
	tb.d2In(d2Sg);
	tb.d3In(d3Sg);
	tb.d4In(d4Sg);
	tb.d5In(d5Sg);
	tb.d6In(d6Sg);
	tb.d7In(d7Sg);


	tb.clkIn(clock);

	tb.s0Out(s0Sg);
	tb.s1Out(s1Sg);
	tb.s2Out(s2Sg);

	sc_start();

	return 0;
}