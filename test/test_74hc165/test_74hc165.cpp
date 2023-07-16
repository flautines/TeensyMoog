#include <Arduino.h>
#include <unity.h>
#include <ic74hc165.h>
#include <moog.h>

void setUp(){}
void tearDown(){}

Ic74hc165 shiftRegister {PIN_LOAD, PIN_DATAIN, PIN_CLOCKIN, PIN_ENABLE};

void test_constructor()
{
	TEST_ASSERT_EQUAL_UINT8(PIN_LOAD, shiftRegister._pinLoad);
	TEST_ASSERT_EQUAL_UINT8(PIN_DATAIN, shiftRegister._pinDataIn);
	TEST_ASSERT_EQUAL_UINT8(PIN_CLOCKIN, shiftRegister._pinClockIn);
	TEST_ASSERT_EQUAL_UINT8(PIN_ENABLE, shiftRegister._pinEnable);
	
	TEST_ASSERT_FALSE(shiftRegister.isInitialized());
}

void test_begin()
{
	shiftRegister.begin();
	TEST_ASSERT_TRUE(shiftRegister.isInitialized());
}

void test_update()
{
	shiftRegister.begin();

	constexpr long CHANGE_POSITION_DELAY = 2000;
	
	uint8_t SHIFT_VALUE = 0x01;

	for (int i=0; i < 6; ++i) {
		shiftRegister.update();
		TEST_ASSERT_EQUAL_UINT8(SHIFT_VALUE, shiftRegister.getValue());
		TEST_MESSAGE("MOVE DIAL TO NEXT POSITION");
		SHIFT_VALUE <<= 1;
		delay(CHANGE_POSITION_DELAY);
	}
}

void setup()
{
	Serial.begin(9600);

	UNITY_BEGIN();
	RUN_TEST(test_constructor);
	RUN_TEST(test_begin);
	RUN_TEST(test_update);
	UNITY_END();
}

void loop()
{
}