#include <Arduino.h>
#include <unity.h>
#include <moog.h>
#include <moogconfig.h>

MoogSynth minimoog;

void setUp()
{	
}

void tearDown()
{
}

void testCreateMoogObject()
{
	TEST_ASSERT_EQUAL_UINT8(A0, minimoog._tunePin);
	TEST_ASSERT_EQUAL_INT8(0, minimoog._semitone[0]);
	TEST_ASSERT_EQUAL_FLOAT(FREQUENCY_RANGE32, minimoog._range[OSCILLATOR_1]);
	TEST_ASSERT_EQUAL_FLOAT(FREQUENCY_RANGE32, minimoog._pitch[0]);
}

void testFrequencyOsc1ForAllRangesAndSemitones()
{
	float ranges[] = {FREQUENCY_RANGE32, FREQUENCY_RANGE16, FREQUENCY_RANGE8, FREQUENCY_RANGE4, FREQUENCY_RANGE2};
	for (float range : ranges) {
		minimoog._range[OSCILLATOR_1] = range;
		for (int semitones =-SEMITONES_IN_TUNE; semitones <= SEMITONES_IN_TUNE; ++semitones) {
			minimoog._semitone[OSCILLATOR_1] = semitones;
			minimoog.update();
			float ratio = powf(2.0f, (float)semitones / 12.0f);
			TEST_ASSERT_FLOAT_WITHIN(0.002, range*ratio, minimoog._pitch[OSCILLATOR_1]);
		}
	}
}

void testFrequencyOsc2ForAllRangesAndSemitones()
{
	minimoog._range[OSCILLATOR_1] = FREQUENCY_RANGE2;
	minimoog._range[OSCILLATOR_2] = FREQUENCY_RANGE4;
	
	for (int8_t semitonesOsc1=-SEMITONES_IN_TUNE; semitonesOsc1 <=SEMITONES_IN_TUNE; ++semitonesOsc1)  {
		minimoog._semitone[OSCILLATOR_1] = semitonesOsc1;
		for (int8_t semitonesOsc2=-SEMITONES_IN_OSC; semitonesOsc2 <= +SEMITONES_IN_OSC; ++semitonesOsc2) {
			minimoog._semitone[OSCILLATOR_2] = semitonesOsc2;
			minimoog.update();
			float ratioOsc1 = getFrequencyRatio(minimoog._semitone[OSCILLATOR_1]);
			float ratioOsc2 = getFrequencyRatio(minimoog._semitone[OSCILLATOR_2]);
			TEST_ASSERT_FLOAT_WITHIN(0.002, FREQUENCY_RANGE2 * ratioOsc1, minimoog._pitch[OSCILLATOR_1]);
			TEST_ASSERT_FLOAT_WITHIN(0.002, FREQUENCY_RANGE4 * ratioOsc1 * ratioOsc2, minimoog._pitch[OSCILLATOR_2]);
		}
	}
}

void testFrequencyOsc3ForAllRangesAndSemitones()
{
	minimoog._range[OSCILLATOR_1] = FREQUENCY_RANGE32;
	minimoog._range[2] = FREQUENCY_RANGE8;
	
	for (int8_t semitonesOsc1=-SEMITONES_IN_TUNE; semitonesOsc1 <=SEMITONES_IN_TUNE; ++semitonesOsc1)  {
		minimoog._semitone[OSCILLATOR_1] = semitonesOsc1;
		for (int8_t semitonesOsc3=-SEMITONES_IN_OSC; semitonesOsc3 <= +SEMITONES_IN_OSC; ++semitonesOsc3) {
			minimoog._semitone[OSCILLATOR_3] = semitonesOsc3;
			minimoog.update();
			float ratioOsc1 = getFrequencyRatio(minimoog._semitone[OSCILLATOR_1]);
			float ratioOsc3 = getFrequencyRatio(minimoog._semitone[OSCILLATOR_3]);
			TEST_ASSERT_FLOAT_WITHIN(0.002, FREQUENCY_RANGE32 * ratioOsc1, minimoog._pitch[OSCILLATOR_1]);
			TEST_ASSERT_FLOAT_WITHIN(0.002, FREQUENCY_RANGE8 * ratioOsc1 * ratioOsc3, minimoog._pitch[OSCILLATOR_3]);
		}
	}
}

void setup()
{
	UNITY_BEGIN();
	RUN_TEST(testCreateMoogObject);
	RUN_TEST(testFrequencyOsc1ForAllRangesAndSemitones);
	RUN_TEST(testFrequencyOsc2ForAllRangesAndSemitones);
	RUN_TEST(testFrequencyOsc3ForAllRangesAndSemitones);
	UNITY_END();
}

void loop()
{

}
