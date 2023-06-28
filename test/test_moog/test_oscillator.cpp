#include <Arduino.h>
#include <Audio.h>
#include <unity.h>
#include <moog.h>
#include <moogconfig.h>

MoogSynth minimoog;

void setUp(void) {

}

void tearDown(void) {

}

void test_constructor(void)
{	
	TEST_ASSERT_EQUAL_INT(A0, minimoog.knobOscillators[0]._pin);
	TEST_ASSERT_EQUAL_INT(A1, minimoog.knobOscillators[1]._pin);
	TEST_ASSERT_EQUAL_INT(A2, minimoog.knobOscillators[2]._pin);
	TEST_ASSERT_EACH_EQUAL_FLOAT(0.0f, minimoog._pitchOscillators, NUM_OSCILLATORS);
	TEST_ASSERT_EACH_EQUAL_FLOAT(0.0f, minimoog.range, NUM_OSCILLATORS);

}

void test_begin(void)
{
	minimoog.begin();
}

void test_update()
{
	minimoog.range[0] = RANGE_16;
	minimoog.range[1] = RANGE_8;
	minimoog.range[2] = RANGE_4;
	minimoog.update();
	TEST_ASSERT_FLOAT_WITHIN(0.5f, 0.0f, fabs(RANGE_16 * 4.0f - minimoog._pitchOscillators[0]));
}

void setup() {
	delay(2000);
	Serial.begin(9600);
	analogReadAveraging(16);

	UNITY_BEGIN();
	
	RUN_TEST(test_constructor);
	
	RUN_TEST(test_begin);
	
	RUN_TEST(test_update);
	

	UNITY_END();
}

void loop() {
	minimoog.update();	
}