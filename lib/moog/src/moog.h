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

	// 0 - Tune, 1 - Oscillator-2, 2 - Oscillator-3
	AnalogKnob knobOscillators[NUM_OSCILLATORS];
	
	float range[NUM_OSCILLATORS];
	

//private:
	void _makePatchConnections();
	AudioSynthWaveform _oscillators[NUM_OSCILLATORS];
	AudioMixer4 _mixer;
	AudioOutputAnalog _dac;
	AudioOutputUSB _usb;
	AudioConnection _patchCoord[NUM_PATCH_CORDS];

	float _oscillators_pitch[NUM_OSCILLATORS];	
	
};

