#include <Arduino.h>
#include <unity.h>
#include <moog.h>

void setUp()
{

}

void tearDown()
{

}

void testCreateMoogObject()
{
	MoogSynth minimoog;
	TEST_ASSERT_EQUAL_UINT8(minimoog._tunePin, A0);
}

void setup()
{
	UNITY_BEGIN();
	RUN_TEST(testCreateMoogObject);
	UNITY_END();
}

void loop()
{

}
