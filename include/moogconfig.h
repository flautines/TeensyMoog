#pragma once

constexpr float FREQUENCY_RANGE32 	=  16.35f;
constexpr float FREQUENCY_RANGE16 	=  32.70f;
constexpr float FREQUENCY_RANGE8  	=  65.40f;
constexpr float FREQUENCY_RANGE4  	= 130.80f;
constexpr float FREQUENCY_RANGE2  	= 261.60f;

constexpr float SEMITONES_IN_TUNE 	= 2.5f;
constexpr float SEMITONES_IN_OSC 	= 7.0f;

constexpr int NUM_OSCILLATORS 		= 3;

// Pin assignments
constexpr uint8_t PIN_LOAD 			= 7;
constexpr uint8_t PIN_CLOCKIN 		= 8;
constexpr uint8_t PIN_DATAIN 		= 9;
constexpr uint8_t PIN_ENABLE 		= 10;


enum {
	OSCILLATOR_1,
	OSCILLATOR_2,
	OSCILLATOR_3,
	NOISE
};