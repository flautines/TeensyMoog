#pragma once

#include <Arduino.h>

class DigitalKnob
{
private:

public:
	DigitalKnob(int positions);
	~DigitalKnob();

	void update();
	int getValue();

	int _value;
	int _positions;
};

