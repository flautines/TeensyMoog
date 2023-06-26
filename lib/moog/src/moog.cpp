#include "moog.h"

MoogSynth::MoogSynth() : 
	knobOscillators { PIN_KNOB_TUNE, PIN_KNOB_OSC_2, PIN_KNOB_OSC_3 },	
	_oscillators_pitch { 0.0f }
{

}

MoogSynth::~MoogSynth()
{
}

void MoogSynth::begin()
{
	_makePatchConnections();

	AudioMemory(20);	

	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_oscillators[i].begin(0.25f, 440, WAVEFORM_SAWTOOTH);
		_mixer.gain(i, 0.25f);		
	}
}

void MoogSynth::update()
{
	for (int i = 0; i < NUM_OSCILLATORS; ++i) knobOscillators[i].update();

	setTune();

	// Update Teensy audio from RANGE, OSC-2/3 and TUNE
	AudioNoInterrupts();
	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_oscillators[i].frequency(_oscillators_pitch[i]);
	}
	AudioInterrupts();
}

void MoogSynth::setTune()
{
	float knobTune, knobOsc2, knobOsc3;
	float tune, oscillator2, oscillator3;

	knobTune = knobOscillators[0].getNormalized();
	knobOsc2 = knobOscillators[1].getNormalized();
	knobOsc3 = knobOscillators[2].getNormalized();

	// TUNE Range -2 .. +2 octaves
	tune = (knobTune - 0.5f) * 4.0f * 12.0f;		
	float tune_offset = pow(2.0f, (tune / 12.0f));

	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_oscillators_pitch[i] = range[i] * tune_offset;
	}

	// Oscillator-2 and Oscillator-3 range from -7 .. +7 semitones
	oscillator2 = (knobOsc2 - 0.5f) * 14.0f;
	oscillator3 = (knobOsc3 - 0.5f) * 14.0f;
	float oscillator2_offset = pow(2.0f, (oscillator2 / 12.0f));
	float oscillator3_offset = pow(2.0f, (oscillator3 / 12.0f));

	_oscillators_pitch[1] = _oscillators_pitch[1] * oscillator2_offset;
	_oscillators_pitch[2] = _oscillators_pitch[2] * oscillator3_offset;
}

void MoogSynth::_makePatchConnections()
{
	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_patchCoord[i].connect(_oscillators[i], 0, _mixer, i);
	}
	_patchCoord[3].connect(_mixer, _dac);
	_patchCoord[4].connect(_mixer, 0, _usb, 0);
	_patchCoord[5].connect(_mixer, 0, _usb, 1);

}