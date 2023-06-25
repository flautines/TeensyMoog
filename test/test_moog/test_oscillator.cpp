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
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog.tune);
	TEST_ASSERT_EQUAL_INT(A0, minimoog.knobTune._pin);
	TEST_ASSERT_EACH_EQUAL_FLOAT(0.0f, minimoog._oscillators_pitch, NUM_OSCILLATORS);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog.oscillator2);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog.oscillator3);
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
	TEST_ASSERT_EQUAL_FLOAT(RANGE_16 * 4.0f, minimoog._oscillators_pitch[0]);
	TEST_ASSERT_EQUAL_FLOAT(RANGE_8  * 4.0f, minimoog._oscillators_pitch[1]);
	TEST_ASSERT_EQUAL_FLOAT(RANGE_4  * 4.0f,minimoog._oscillators_pitch[2]);
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