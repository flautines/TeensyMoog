#pragma once
#include <Arduino.h>

class MoogSynth
{
public:
	MoogSynth();
	~MoogSynth();

	void update();

//private:
	uint8_t _tunePin;	
	int8_t _semitoneOffsetOsc1;
	float _range;
	float _osc1Pitch;
};
