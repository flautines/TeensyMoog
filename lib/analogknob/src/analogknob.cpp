#include <analogknob.h>

float normalize(int value);

AnalogKnob::AnalogKnob(uint8_t pin, float maxPositiveValue) : 
	_pin {pin}, 
	_rawValue {0}, 
	_maxValue {maxPositiveValue}
{
}

AnalogKnob::~AnalogKnob()
{
}

float AnalogKnob::getValue()
{
	float valueNormalized = normalize(_rawValue);
	float mappedValue = _mapEquidistant(valueNormalized);

	return mappedValue;
}

float normalize(int value)
{
	float valueNormalized = (float)value / 1023.0;
	if (fabs(valueNormalized - 0.5f) < 0.002f) valueNormalized = 0.5f;

	return valueNormalized;
}

float AnalogKnob::_mapEquidistant(float value)
{
	return (value - 0.5f) * 2.0f * _maxValue;
}
