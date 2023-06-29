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
	TEST_ASSERT_EQUAL_INT8(0, minimoog._semitoneOffsetOsc1);
	TEST_ASSERT_EQUAL_FLOAT(FREQUENCY_RANGE32, minimoog._range);
	TEST_ASSERT_EQUAL_FLOAT(FREQUENCY_RANGE32, minimoog._osc1Pitch);
}

void testFrequencyOsc1ForAllRangesAndSemitones()
{
	float ranges[] = {FREQUENCY_RANGE32, FREQUENCY_RANGE16, FREQUENCY_RANGE8, FREQUENCY_RANGE4, FREQUENCY_RANGE2};
	for (float range : ranges) {
		minimoog._range = range;
		for (int semitones =-24; semitones <= 24; ++semitones) {
			minimoog._semitoneOffsetOsc1 = semitones;
			minimoog.update();
			float ratio = powf(2.0f, (float)semitones / 12.0f);
			TEST_ASSERT_FLOAT_WITHIN(0.002, range*ratio, minimoog._osc1Pitch);
		}
	}
}

void setup()
{
	UNITY_BEGIN();
	RUN_TEST(testCreateMoogObject);
	RUN_TEST(testFrequencyOsc1ForAllRangesAndSemitones);
	UNITY_END();
}

void loop()
{

}
