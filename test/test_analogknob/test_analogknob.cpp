#include <Arduino.h>
#include <unity.h>
#include <analogknob.h>

void setUp(){}
void tearDown(){}

AnalogKnob knob24(3, 24.f);

void test_createAnalogKnob()
{
	TEST_ASSERT_EQUAL_UINT8(3, knob24._pin);
	TEST_ASSERT_EQUAL_INT(0, knob24._rawValue);
	TEST_ASSERT_EQUAL_FLOAT(24.f, knob24._maxValue);
}

void test_getValue() {
	knob24._rawValue = 0;	
	TEST_ASSERT_FLOAT_WITHIN(0.002, -24.f, knob24.getValue());

	knob24._rawValue = 255;
	TEST_ASSERT_FLOAT_WITHIN(0.05, -12.f, knob24.getValue());

	knob24._rawValue = 511;
	TEST_ASSERT_FLOAT_WITHIN(0.002, 0.f, knob24.getValue());

	knob24._rawValue = 767;
	TEST_ASSERT_FLOAT_WITHIN(0.05, 12.f, knob24.getValue());

	knob24._rawValue = 1023;
	TEST_ASSERT_FLOAT_WITHIN(0.002, 24.f, knob24.getValue());

	AnalogKnob knob7(4, 7);
	knob7._rawValue = 0;	
	TEST_ASSERT_FLOAT_WITHIN(0.002, -7.f, knob7.getValue());

	knob7._rawValue = 255;
	TEST_ASSERT_FLOAT_WITHIN(0.05, -3.5f, knob7.getValue());

	knob7._rawValue = 511;
	TEST_ASSERT_FLOAT_WITHIN(0.002, 0.f, knob7.getValue());

	knob7._rawValue = 767;
	TEST_ASSERT_FLOAT_WITHIN(0.05, 3.5f, knob7.getValue());

	knob7._rawValue = 1023;
	TEST_ASSERT_FLOAT_WITHIN(0.002, 7.f, knob7.getValue());	
}

void setup()
{
	UNITY_BEGIN();
	RUN_TEST(test_createAnalogKnob);
	RUN_TEST(test_getValue);
	UNITY_END();
}

void loop()
{

}