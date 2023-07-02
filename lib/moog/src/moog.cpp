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

	for (int oscillatorId = 0; oscillatorId < NUM_OSCILLATORS; ++oscillatorId) {
		setTuneOscillator(oscillatorId);
	}

	updateAudio();
}

void MoogSynth::setTuneOscillator(int oscillatorId)
{
	AnalogKnob knob = knobOscillators[0];
	float semitones = getSemitonesFromKnob(knob, SEMITONES_IN_TUNE);
	float frequencyScale = getFrequencyScaleFromSemitones(semitones);

	_pitchOscillators[oscillatorId] = range[oscillatorId] * frequencyScale;

	if (oscillatorId > 0) {
		knob = knobOscillators[oscillatorId];
		semitones = getSemitonesFromKnob(knob, SEMITONES_IN_OSC);
		frequencyScale = getFrequencyScaleFromSemitones(semitones);
		_pitchOscillators[oscillatorId] *= frequencyScale;
	}
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

float MoogSynth::getSemitonesFromKnob(const AnalogKnob& knob, float semitones)
{
	float knobValue = knob.getNormalized();
	return ( (knobValue - 0.5f) * 2.0f * semitones );
}

float MoogSynth::getFrequencyScaleFromSemitones(float semitones)
{
	return pow(2.0f, (semitones / 12.0f));
}