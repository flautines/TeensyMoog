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

	AnalogKnob knobOscillators[NUM_OSCILLATORS];
	
	float range[NUM_OSCILLATORS];
	

//private:
	void makePatchConnections();
	void initializeOscillators();
	void setDefaultOscillatorsVolume();
	void updateAllKnobs();
	void updateAudio();

	AudioSynthWaveform _audioOscillators[NUM_OSCILLATORS];
	AudioMixer4 _audioMixer;
	AudioOutputAnalog _audioDac;
	AudioOutputUSB _audioUsb;
	AudioConnection _audioPatch[NUM_PATCH_CORDS];

	float _pitchOscillators[NUM_OSCILLATORS];	
	
};

