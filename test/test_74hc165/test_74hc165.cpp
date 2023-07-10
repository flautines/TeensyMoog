#include <Arduino.h>
#include <unity.h>

void setUp(){}
void tearDown(){}

// PL pin 1
constexpr uint8_t pinLoad = 7;
// CE pin 15
constexpr uint8_t pinClockEnable = 10;
// Q7 pin 7
constexpr uint8_t pinDataIn = 9;
// CP pin 2
constexpr uint8_t pinClockIn = 8;

void setup()
{
	Serial.begin(9600);

	// Setup 74HC165 connections
	pinMode(pinLoad, OUTPUT);
	pinMode(pinClockEnable, OUTPUT);
	pinMode(pinClockIn, OUTPUT);
	pinMode(pinDataIn, INPUT);
}

void loop()
{
	// Write pulse to load pin
	digitalWrite(pinLoad, LOW);
	delayMicroseconds(5);
	digitalWrite(pinLoad, HIGH);
	delayMicroseconds(5);

	// Get data from 74HC165
	digitalWrite(pinClockIn, HIGH);
	//digitalWrite(pinClockEnable, LOW);
	byte incoming = shiftIn(pinDataIn, pinClockIn, MSBFIRST);
	digitalWrite(pinClockEnable, HIGH);

	// Print to serial monitor
	Serial.println(incoming, BIN);
	delay(200);
}