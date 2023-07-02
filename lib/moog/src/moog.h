#pragma once
#include <Arduino.h>
#include <moogconfig.h>

class MoogSynth
{
public:
	MoogSynth();
	~MoogSynth();

	void update();
	/*
	float getRange(int oscillator) const;
	void setRange(int oscillator, float range);
	float getPitch(int oscillator) const;
	void setPitch(int oscillator, float pitch);
	*/
	

//private:
	uint8_t _tunePin;	
	int8_t _semitone[NUM_OSCILLATORS];
	float _range[NUM_OSCILLATORS];
	float _pitch[NUM_OSCILLATORS];
};

///////////////////////////////////////////////////////////
// AUXILIARY FUNCTIONS DECLARATION
///////////////////////////////////////////////////////////
float getFrequencyRatio(int8_t semitones);