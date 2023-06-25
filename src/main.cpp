#include <Arduino.h>
#include "moog.h"

MoogSynth minimoog;

void setup() {
	minimoog.begin();
}

void loop() {
	minimoog.update();
}