#include <Arduino.h>
#include "moog.h"

MoogSynth minimoog;

void setup() {
	minimoog.begin();
	minimoog.range[0] = RANGE_16;
	minimoog.range[1] = RANGE_8;
	minimoog.range[2] = RANGE_4;
}

void loop() {
	minimoog.update();
}