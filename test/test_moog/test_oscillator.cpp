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
	TEST_ASSERT_NOT_NULL(&minimoog);
	TEST_ASSERT_EACH_EQUAL_FLOAT(0.0f, minimoog._oscillators_pitch, NUM_OSCILLATORS);
}

void test_begin(void)
{
	minimoog.begin();
}

void test_update()
{
	minimoog.update();
}

void setup() {
	delay(2000);
	Serial.begin(9600);
	analogReadAveraging(16);

	UNITY_BEGIN();
	RUN_TEST(test_constructor);
	RUN_TEST(test_begin);
	UNITY_END();
}

void loop() {
	
}