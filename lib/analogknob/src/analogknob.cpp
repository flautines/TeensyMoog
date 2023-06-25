#include "analogknob.h"

AnalogKnob::AnalogKnob(uint8_t pin) : _pin {pin}, _value {0}, _normalized {0.0f}
{
}

AnalogKnob::~AnalogKnob()
{
}

void AnalogKnob::update()
{
	_value = analogRead(_pin);
	_normalized = _value / 1024.0f;
	if (_normalized < 0.002) {
		_value = 0;
		_normalized = 0.0f;
	}
}