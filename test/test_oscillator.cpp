#include <Arduino.h>
#include <Audio.h>
#include "unity.h"
#include <moog.h>

MoogSynth synth;

void setUp(void) {

}

void tearDown(void) {

}

void test_constructor(void)
{	
	TEST_ASSERT_NOT_NULL(&synth);
}

void test_begin(void)
{
	synth.begin();
}

void setup() {
	delay(2000);
	Serial.begin(9600);
	UNITY_BEGIN();
	RUN_TEST(test_constructor);
	UNITY_END();
}

void loop() {

}