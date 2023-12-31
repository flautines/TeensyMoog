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
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog._pitchOscillators[0]);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog._pitchOscillators[1]);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog._pitchOscillators[2]);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog.range[0]);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog.range[1]);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, minimoog.range[2]);

}

void test_begin(void)
{
	minimoog.begin();
}

void test_update()
{
	minimoog.range[0] = RANGE_8;
	minimoog.range[1] = RANGE_8;
	minimoog.range[2] = RANGE_4;
	minimoog.update();
	TEST_ASSERT_FLOAT_WITHIN(0.5f, RANGE_8, minimoog._pitchOscillators[0]);
	//TEST_ASSERT_FLOAT_WITHIN(0.5f, 0.0f, fabs(RANGE_16 * 4.0f - minimoog._pitchOscillators[0]));
}

void setup() {
	delay(2000);
	Serial.begin(9600);
	analogReadAveraging(16);

	UNITY_BEGIN();
	
	RUN_TEST(test_constructor);
	
	RUN_TEST(test_begin);
	
	for (int i=0; i<15; i++) {
		RUN_TEST(test_update);
		delay(250);
	}

	UNITY_END();
}

void loop() {
	minimoog.update();	
}