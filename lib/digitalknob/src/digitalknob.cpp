#include <digitalknob.h>

DigitalKnob::DigitalKnob(int positions) : 
	_value {0}, 
	_positions {positions}
{
}

DigitalKnob::~DigitalKnob()
{
}

int DigitalKnob::getValue()
{
	return _value;
}

void DigitalKnob::update()
{
	if (_value+1 < _positions) {
		_value++;
	}
}