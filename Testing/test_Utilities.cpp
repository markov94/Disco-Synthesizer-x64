#include "CppUTest/TestHarness.h"
#include "Utilities.h"

TEST_GROUP(Utilities)
{
	void setup() {}
	void teardown() {}
};


TEST(Utilities, isPowerOfTwo_0_false)
{
	CHECK_FALSE(Utilities::isPowerOfTwo(0));
}

TEST(Utilities, isPowerOfTwo_1_true)
{
	CHECK(Utilities::isPowerOfTwo(1));
}

TEST(Utilities, isPowerOfTwo_2_true)
{
	CHECK(Utilities::isPowerOfTwo(2));
}

TEST(Utilities, isPowerOfTwo_3_false)
{
	CHECK_FALSE(Utilities::isPowerOfTwo(3));
}

TEST(Utilities, isPowerOfTwo_64_true)
{
	CHECK(Utilities::isPowerOfTwo(64));
}

TEST(Utilities, isPowerOfTwo_127_false)
{
	CHECK_FALSE(Utilities::isPowerOfTwo(127));
}

TEST(Utilities, isPowerOfTwo_256_true)
{
	CHECK(Utilities::isPowerOfTwo(256));
}