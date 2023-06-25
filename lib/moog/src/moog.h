#include <Arduino.h>
#include <Audio.h>
#include "moogconfig.h"
#include "analogknob.h"

class MoogSynth
{
public:
	MoogSynth();
	~MoogSynth();

	void begin();
	void update();
	void setTune();

	float tune;
	AnalogKnob knobTune;
	float range[NUM_OSCILLATORS];
	float oscillator2;
	float oscillator3;

//private:
	void _makePatchConnections();
	AudioSynthWaveform _oscillators[NUM_OSCILLATORS];
	AudioMixer4 _mixer;
	AudioOutputAnalog _dac;
	AudioOutputUSB _usb;
	AudioConnection _patchCoord[NUM_PATCH_CORDS];

	float _oscillators_pitch[NUM_OSCILLATORS];	
	
};

