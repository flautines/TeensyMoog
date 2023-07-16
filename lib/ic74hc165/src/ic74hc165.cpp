#include <ic74hc165.h>

uint8_t myShiftIn_msbFirst(uint8_t dataPin, uint8_t clockPin);

Ic74hc165::Ic74hc165(uint8_t pinLoad, 
					 uint8_t pinDataIn, 
					 uint8_t pinClockIn,
					 uint8_t pinEnable) : 
	_pinLoad {pinLoad}, 
	_pinDataIn {pinDataIn}, 
	_pinClockIn {pinClockIn},
	_pinEnable {pinEnable},
	_isInitialized {false}
{
}

Ic74hc165::~Ic74hc165()
{
}

bool Ic74hc165::isInitialized()
{
	return _isInitialized;
}

void Ic74hc165::begin()
{
	pinMode(_pinLoad, OUTPUT);
	pinMode(_pinClockIn, OUTPUT);
	pinMode(_pinDataIn, INPUT);
	pinMode(_pinEnable, OUTPUT);

	_isInitialized = true;

	delay(20);
	update();
	
}

void Ic74hc165::update()
{
	// Write pulse to load pin
	digitalWrite(_pinLoad, LOW);
	delayMicroseconds(5);
	digitalWrite(_pinLoad, HIGH);
	delayMicroseconds(5);

	// Get data from 74HC165
	digitalWrite(_pinClockIn, HIGH);
	digitalWrite(_pinEnable, LOW);
	_value = myShiftIn_msbFirst(_pinDataIn, _pinClockIn);
	digitalWrite(_pinEnable, HIGH);
}

uint8_t Ic74hc165::getValue()
{
	return _value;
}

/////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
/////////////////////////////////////////////////////////////////////////////

// Does the same thing as ShiftIn, but with delay to avoid problems with
// teensy speeds.
uint8_t myShiftIn_msbFirst(uint8_t dataPin, uint8_t clockPin)
{
	uint8_t mask;
	uint8_t value = 0;

	for (mask = 0x80; mask; mask >>=1) {
		digitalWrite(clockPin, HIGH);
		delayMicroseconds(1);
		if (digitalRead(dataPin)) {
			value |= mask;
		}
		digitalWrite(clockPin, LOW);
		delayMicroseconds(1);
	}

	return value;
}