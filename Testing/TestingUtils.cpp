#include "TestingUtils.h"

bool TestingUtils::AreSame(const float a, const float b, const float epsilon)
{
	return fabs(a - b) < epsilon;
}
