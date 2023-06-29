#include "moog.h"
#include <moogconfig.h>

float getFrequencyRatio(int8_t semitones);

MoogSynth::MoogSynth() : 
	_tunePin {A0}, 
	_semitoneOffsetOsc1 {0}, 
	_range {FREQUENCY_RANGE32},
	_osc1Pitch {FREQUENCY_RANGE32}
{
}

MoogSynth::~MoogSynth()
{
}

void MoogSynth::update()
{
	_osc1Pitch = _range * getFrequencyRatio(_semitoneOffsetOsc1);
}

///////////////////////////////////////////////////////////
// AUXILIARY PRIVATE FUNCTIONS
///////////////////////////////////////////////////////////
float getFrequencyRatio(int8_t semitones)
{
	return powf(2.0f, (float)semitones / 12.0f);
}