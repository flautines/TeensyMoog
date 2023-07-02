#pragma once
#include <Arduino.h>

class AnalogKnob
{
public:
	AnalogKnob(uint8_t pin, float maxPositiveValue);
	~AnalogKnob();

	float getValue();	

	uint8_t _pin;
	int _rawValue;
	float _maxValue;

private:
	float _mapEquidistant(float value);	
};
