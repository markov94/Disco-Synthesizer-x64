#pragma once
#include "OutputBuffer.h"
#include "CppUTest/TestHarness.h"
#include "TestingUtils.h"

static float constexpr EPSILON_FOR_MODULES = 0.00001f;
void testModulesOutput(OutputBuffer* testedOutputBuffer, const float* expectedData)
{
	float* testedData = testedOutputBuffer->getData();
	for (unsigned i = 0; i < testedOutputBuffer->getDataSize(); i++)
	{
		CHECK(TestingUtils::AreSame(testedData[i], expectedData[i], EPSILON_FOR_MODULES));
		
	}
}