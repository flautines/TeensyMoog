#include <Arduino.h>
#include <unity.h>
#include <digitalknob.h>

void setUp() {}
void tearDown() {}

void test_constructor()
{
	DigitalKnob range01 {6};
	TEST_ASSERT_EQUAL_INT(0, range01.getValue());
	TEST_ASSERT_EQUAL_INT(6, range01._positions);
}

void test_getValue()
{
	DigitalKnob range01 {6};

	TEST_ASSERT_EQUAL_INT(0, range01.getValue());
}

void test_update()
{
	DigitalKnob range01 {6};

	TEST_ASSERT_EQUAL_INT(0, range01.getValue());
	range01.update();
	TEST_ASSERT_EQUAL_INT(1, range01.getValue());
	range01.update();
	TEST_ASSERT_EQUAL_INT(2, range01.getValue());
	range01.update();
	TEST_ASSERT_EQUAL_INT(3, range01.getValue());
	range01.update();
	TEST_ASSERT_EQUAL_INT(4, range01.getValue());
	range01.update();
	TEST_ASSERT_EQUAL_INT(5, range01.getValue());
	range01.update();
	TEST_ASSERT_EQUAL_INT(5, range01.getValue());
}

void setup()
{
	Serial.begin(9600);

	UNITY_BEGIN();
	RUN_TEST(test_constructor);	
	RUN_TEST(test_getValue);
	RUN_TEST(test_update);
	UNITY_END();
}

void loop()
{

}