#include <Arduino.h>
#include <unity.h>
#include <analogknob.h>

AnalogKnob knob(A0);

void setUp(void)
{

}

void tearDown(void)
{

}

void test_constr(void)
{
	TEST_ASSERT_EQUAL_INT(A0, knob._pin);
	TEST_ASSERT_EQUAL_INT(0, knob._value);
	TEST_ASSERT_EQUAL_FLOAT(0.0f, knob._normalized);
}

void test_update(void)
{
	//TEST_ASSERT_GREATER_OR_EQUAL(0.0f, knob._normalized);
	//TEST_ASSERT_LESS_OR_EQUAL(1.0f, knob._normalized);
	//TEST_ASSERT_EQUAL_FLOAT(knob._value/1024.0f, knob._normalized);
	TEST_MESSAGE("Turn knob to the LEFT");
	delay(5000);
	for (int i=0; i<15; ++i) {
		knob.update();
		TEST_ASSERT_EQUAL_FLOAT(0.0f, knob._normalized);
		delay(250);
	}

	TEST_MESSAGE("Turn knob to the RIGHT");
	delay(5000);
	for (int i=0; i<15; ++i) {
		knob.update();
		TEST_ASSERT_GREATER_OR_EQUAL(0.99f, knob._normalized);
		TEST_ASSERT_LESS_OR_EQUAL(1.0f, knob._normalized);
		delay(250);
	}
}

void test_getValue()
{
	TEST_ASSERT_EQUAL_INT(knob._value, knob.getValue());	
}

void test_getNormalized()
{
	TEST_ASSERT_EQUAL_FLOAT(knob._normalized, knob.getNormalized());
	TEST_ASSERT_EQUAL_FLOAT(knob.getValue()/1024.0f, knob.getNormalized());
}

void setup()
{
	delay(2000);
	Serial.begin(9600);
	analogReadAveraging(32);

	UNITY_BEGIN();
	RUN_TEST(test_constr);
	//RUN_TEST(test_update);
	for (int i=0; i < 32; ++i)
	{
		knob.update();
		RUN_TEST(test_getValue);
		RUN_TEST(test_getNormalized);
		delay(250);
	}
	UNITY_END();
}

void loop()
{

}