#include <Arduino.h>
#include <Audio.h>
#include "moogconfig.h"

class MoogSynth
{
public:
	MoogSynth();
	~MoogSynth();

	void begin();

private:
	AudioSynthWaveform oscillators[NUM_OSCILLATORS];
};

