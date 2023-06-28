#include "moog.h"

MoogSynth::MoogSynth() : 
	knobOscillators { PIN_KNOB_TUNE, PIN_KNOB_OSC_2, PIN_KNOB_OSC_3 },	
	_pitchOscillators { 0.0f }
{

}

MoogSynth::~MoogSynth()
{
}

void MoogSynth::begin()
{
	makePatchConnections();

	AudioMemory(20);	

	initializeOscillators();
	setDefaultOscillatorsVolume();
}

void MoogSynth::update()
{
	updateAllKnobs();

	setTune();

	updateAudio();
}

void MoogSynth::setTune()
{
	float tune, oscillator2, oscillator3;

	float knobTune = knobOscillators[0].getNormalized();
	float knobOsc2 = knobOscillators[1].getNormalized();
	float knobOsc3 = knobOscillators[2].getNormalized();

	// TUNE Range -2 .. +2 octaves
	tune = (knobTune - 0.5f) * 4.0f * 12.0f;		
	float tune_offset = pow(2.0f, (tune / 12.0f));

	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_pitchOscillators[i] = range[i] * tune_offset;
	}

	// Oscillator-2 and Oscillator-3 range from -7 .. +7 semitones
	oscillator2 = (knobOsc2 - 0.5f) * 14.0f;
	oscillator3 = (knobOsc3 - 0.5f) * 14.0f;
	float oscillator2_offset = pow(2.0f, (oscillator2 / 12.0f));
	float oscillator3_offset = pow(2.0f, (oscillator3 / 12.0f));

	_pitchOscillators[1] = _pitchOscillators[1] * oscillator2_offset;
	_pitchOscillators[2] = _pitchOscillators[2] * oscillator3_offset;
}

///////////////////////////////////////////////////////////
// PRIVATE INTERFACE
///////////////////////////////////////////////////////////
void MoogSynth::makePatchConnections()
{
	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_audioPatch[i].connect(_audioOscillators[i], 0, _audioMixer, i);
	}
	_audioPatch[3].connect(_audioMixer, _audioDac);
	_audioPatch[4].connect(_audioMixer, 0, _audioUsb, 0);
	_audioPatch[5].connect(_audioMixer, 0, _audioUsb, 1);

}

void MoogSynth::initializeOscillators()
{
	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_audioOscillators[i].begin(0.25f, 440, WAVEFORM_SAWTOOTH);
	}
}

void MoogSynth::setDefaultOscillatorsVolume()
{
	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_audioMixer.gain(i, 0.25f);
	}
}

void MoogSynth::updateAllKnobs()
{
	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		knobOscillators[i].update();
	}
}

void MoogSynth::updateAudio()
{
	// Update Teensy audio from RANGE, OSC-2/3 and TUNE
	AudioNoInterrupts();
	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_audioOscillators[i].frequency(_pitchOscillators[i]);
	}
	AudioInterrupts();	
}