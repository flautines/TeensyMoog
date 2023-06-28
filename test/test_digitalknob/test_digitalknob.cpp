#include <Arduino.h>
#include <unity.h>
#include <digitalknob.h>

DigitalKnob knob_wave1(3);

void setUp() {}

void tearDown() {}

void test_constr()
{
	TEST_ASSERT_EQUAL_UINT8(3, knob_wave1._pin);
}

void test_update()
{
	knob_wave1.update();
	TEST_ASSERT_BITS_LOW(0xdf, knob_wave1._value);
	TEST_ASSERT_EQUAL_UINT8(0x20, knob_wave1._value);
}

void test_getPosition()
{
	uint8_t pos = knob_wave1.getPosition();
	TEST_ASSERT_EQUAL_UINT8(5, pos);

	knob_wave1._value = 0x10;
	pos = knob_wave1.getPosition();
	TEST_ASSERT_EQUAL_UINT8(4, pos);

	knob_wave1._value = 0x08;
	pos = knob_wave1.getPosition();
	TEST_ASSERT_EQUAL_UINT8(3, pos);

	knob_wave1._value = 0x04;
	pos = knob_wave1.getPosition();
	TEST_ASSERT_EQUAL_UINT8(2, pos);

	knob_wave1._value = 0x02;
	pos = knob_wave1.getPosition();
	TEST_ASSERT_EQUAL_UINT8(1, pos);

	knob_wave1._value = 0x01;
	pos = knob_wave1.getPosition();
	TEST_ASSERT_EQUAL_UINT8(0, pos);
}

void setup()
{
	delay(2000);
	Serial.begin(9600);
	UNITY_BEGIN();
	RUN_TEST(test_constr);
	RUN_TEST(test_update);
	RUN_TEST(test_getPosition);
	UNITY_END();
}

void loop()
{

}