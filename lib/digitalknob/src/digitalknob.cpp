#include "digitalknob.h"

DigitalKnob::DigitalKnob(uint8_t pin) : _pin { pin }
{
}

DigitalKnob::~DigitalKnob()
{
}

void DigitalKnob::update()
{
	_value = 0x20;
}

uint8_t DigitalKnob::getPosition() const
{
	int pos = 0;
	uint8_t value = _value;
	while ( LSBEqualsZero(value) ) {
		value >>= 1;
		pos++;
	}
	return pos;
}

///////////////////////////////////////////////////////////
// PRIVATE INTERFACE
///////////////////////////////////////////////////////////
bool DigitalKnob::LSBEqualsZero(uint8_t value) const
{
	return !(value & 0x01);
}