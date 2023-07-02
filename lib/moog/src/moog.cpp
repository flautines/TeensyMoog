#include "moog.h"
#include <moogconfig.h>

float getFrequencyRatio(int8_t semitones);

MoogSynth::MoogSynth() : 
	_tunePin {A0}, 
	_semitone {0},
	_range {FREQUENCY_RANGE32},
	_pitch {FREQUENCY_RANGE32}
{
}

MoogSynth::~MoogSynth()
{
}

void MoogSynth::update()
{
	float ratioOsc1 = getFrequencyRatio(_semitone[OSCILLATOR_1]);
	float ratioOsc2 = getFrequencyRatio(_semitone[OSCILLATOR_2]);
	float ratioOsc3 = getFrequencyRatio(_semitone[OSCILLATOR_3]);
	_pitch[OSCILLATOR_1] = _range[OSCILLATOR_1] * ratioOsc1;
	_pitch[OSCILLATOR_2] = _range[OSCILLATOR_2] * ratioOsc1 * ratioOsc2;
	_pitch[OSCILLATOR_3] = _range[OSCILLATOR_3] * ratioOsc1 * ratioOsc3;
}

///////////////////////////////////////////////////////////
// AUXILIARY FUNCTIONS IMPLEMENTATION
///////////////////////////////////////////////////////////
float getFrequencyRatio(int8_t semitones)
{
	return powf(2.0f, (float)semitones / 12.0f);
}