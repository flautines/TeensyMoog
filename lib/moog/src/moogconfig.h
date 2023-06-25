#pragma once

constexpr int NUM_OSCILLATORS 	= 3;
constexpr int NUM_PATCH_CORDS 	= 15;

///////////////////////////////////////////////////////////
//  Feet	Frequency
//  32'		16.35 Hz
//  16'		32.70 Hz
//   8'		65.41 Hz
//   4'		130.81 Hz
//   2'		261.63 Hz
///////////////////////////////////////////////////////////
#define RANGE_32 16.35f
#define RANGE_16 RANGE_32 * 2
#define RANGE_8 RANGE_16 * 2
#define RANGE_4 RANGE_8 * 2
#define RANGE_2 RANGE_4 * 2

///////////////////////////////////////////////////////////
// PIN ASSIGNMENT
///////////////////////////////////////////////////////////
constexpr int PIN_KNOB_TUNE 	= A0;
constexpr int PIN_KNOB_OSC_2 	= A1;
constexpr int PIN_KNOB_OSC_3 	= A2;