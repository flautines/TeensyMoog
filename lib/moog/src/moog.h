#include <Arduino.h>
#include <Audio.h>
#include "moogconfig.h"

class MoogSynth
{
public:
	MoogSynth();
	~MoogSynth();

	void begin();
	void update();
	void setTune();

	float tune;

private:
	void _makePatchConnections();
	AudioSynthWaveform _oscillators[NUM_OSCILLATORS];
	AudioMixer4 _mixer;
	AudioOutputAnalog _dac;
	AudioOutputUSB _usb;
	AudioConnection _patchCoord[NUM_PATCH_CORDS];

public:
	float _oscillators_pitch[NUM_OSCILLATORS];
};

