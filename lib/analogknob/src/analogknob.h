#pragma once
#include <Arduino.h>

class AnalogKnob {
public:
	AnalogKnob(uint8_t pin);
	~AnalogKnob();
	void update();
	inline int getValue() { return _value; }
	inline float getNormalized() { return _normalized; }
	
//private:
	uint8_t _pin;
	int _value;
	float _normalized;
};