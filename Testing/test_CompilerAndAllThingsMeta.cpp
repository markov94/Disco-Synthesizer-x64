#include "CppUTest/TestHarness.h"
#include <stdexcept>

TEST_GROUP(MetaTesting)
{
	void setup() {}
	void teardown() {}
};


void throwException()
{
	throw std::runtime_error("Errno 1");
}

TEST(MetaTesting, test_throwException_getsChecked)
{
	CHECK_THROWS(std::runtime_error,throwException());
}
