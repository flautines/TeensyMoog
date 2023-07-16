#pragma once

#include <Arduino.h>

class Ic74hc165
{
private:

public:
	Ic74hc165(uint8_t pinLoad, 
			  uint8_t pinDataIn, 
			  uint8_t pinClockIn, 
			  uint8_t pinEnable);
	~Ic74hc165();

	bool isInitialized();
	void begin();
	void update();
	uint8_t getValue();

	uint8_t _pinLoad;
	uint8_t _pinDataIn;
	uint8_t _pinClockIn;
	uint8_t _pinEnable;

	bool _isInitialized;

	uint8_t _value;
};

