#include "moog.h"

MoogSynth::MoogSynth() : 
	tune { 0.0f },
	knobTune { PIN_KNOB_TUNE },
	oscillator2 { 0.0f }, 
	oscillator3 { 0.0f },
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
	knobTune.update();

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
	// TUNE Range -2 .. +2 octaves
	tune = (knobTune.getNormalized() - 0.5f) * 4.0f * 12.0f;		
	float semitone = pow(2.0f, (tune / 12.0f));

	for (int i = 0; i < NUM_OSCILLATORS; ++i) {
		_oscillators_pitch[i] = range[i] * semitone;
	}

	// Oscillator-2 and Oscillator-3 add an offset to each oscillator to main tune
	//oscillator2 = ()
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