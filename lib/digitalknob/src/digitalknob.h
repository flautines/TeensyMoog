#pragma once
#include <Arduino.h>

class DigitalKnob
{
public:
	DigitalKnob(uint8_t pin);
	~DigitalKnob();
	void update();
	uint8_t getPosition() const;

	uint8_t _pin;
	uint8_t _value;

private:
	bool LSBEqualsZero(uint8_t value) const;
};