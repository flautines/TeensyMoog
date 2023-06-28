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

constexpr float NUM_OCTAVES_IN_TUNE_KNOB = 2.0f;
constexpr float NUM_SEMITONES_PER_OCTAVE = 12.0f;
constexpr float NUM_SEMITONES_IN_TUNE_KNOB = NUM_SEMITONES_PER_OCTAVE * NUM_OCTAVES_IN_TUNE_KNOB;
constexpr float NUM_SEMITONES_IN_OSC_KNOB = 7.0f;

///////////////////////////////////////////////////////////
// PIN ASSIGNMENT
///////////////////////////////////////////////////////////
constexpr int PIN_KNOB_TUNE 	= A0;
constexpr int PIN_KNOB_OSC_2 	= A1;
constexpr int PIN_KNOB_OSC_3 	= A2;

constexpr int PIN_KNOB_VOL_1	= A3;
constexpr int PIN_KNOB_VOL_2	= A4;
constexpr int PIN_KNOB_VOL_3	= A5;
constexpr int PIN_KNOB_VOL_NOISE = A6;

constexpr int PIN_KNOB_CUTOFF	= A7;
constexpr int PIN_KNOB_EMPH		= A8;

constexpr int PIN_KNOB_ATTACK	= A9;
constexpr int PIN_KNOB_DECAY	= A10;
constexpr int PIN_KNOB_SUSTAIN	= A11;