#include "CppUTest/TestHarness.h"
#include "InputConverters.h"
#include "TestingUtils.h"
#include "TestingResources.h"


static float constexpr EPSILON_FOR_CONVERTERS = 0.00001f;

static void testSampleConversion(InputConverter* testedConverter, float inputSample, float expectedResult)
{
	CHECK(TestingUtils::AreSame(expectedResult, testedConverter->convertSample(inputSample), EPSILON_FOR_CONVERTERS));
}

static void testEverySampleConversion(InputConverter* testedConverter, const float* inputBuffer, const float* expectedResults, unsigned numberOfSamples)
{
	for (unsigned i = 0; i < numberOfSamples; i++)
	{
		testSampleConversion(testedConverter, inputBuffer[i], expectedResults[i]);
	}
}

static void testBufferConversion(InputConverter* testedConverter, const float* inputBuffer, const float* expectedResults,unsigned numberOfSamples)
{
	float* output = new float[numberOfSamples];
	testedConverter->convertBuffer(inputBuffer, output, numberOfSamples);


	for (unsigned i = 0; i < numberOfSamples; i++)
	{
		CHECK(TestingUtils::AreSame(output[i], expectedResults[i], EPSILON_FOR_CONVERTERS));
	}

	delete[] output;
}

TEST_GROUP(StandardAudioInputConverter)
{
	void setup() {}
	void teardown() {}
};

TEST(StandardAudioInputConverter, convertSample_hasValidInputValue_returnsTheSameValue)
{
	StandardAudioInputConverter converter;
	testEverySampleConversion(&converter, oracleStandardInput, oracleStandardInput, oracleStandardInputSize);
}

TEST(StandardAudioInputConverter, convertSample_hasValidInputBuffer_copiesSameValuesToNewBuffer)
{
	StandardAudioInputConverter converter;
	testBufferConversion(&converter, oracleStandardInput, oracleStandardInput, oracleStandardInputSize);

}

TEST_GROUP(LinearGainInputConverter)
{
	void setup() {}
	void teardown() {}
};

TEST(LinearGainInputConverter, convertSample_Oracle0ToMinus40_returnsMatchOracle)
{
	LinearGainInputConverter converter(0.0, -40.0);
	testEverySampleConversion(&converter, oracleStandardInput, oracleLinearGainConverterOutput_0dB_Minus40dB, oracleStandardInputSize);
}

TEST(LinearGainInputConverter, convertBuffer_Oracle0ToMinus40_outputBufferMatchesOracle)
{
	LinearGainInputConverter converter(0.0, -40.0);
	testBufferConversion(&converter, oracleStandardInput, oracleLinearGainConverterOutput_0dB_Minus40dB, oracleStandardInputSize);
}

TEST_GROUP(LogarythmicGainInputConverter)
{
	void setup() {}
	void teardown() {}
};

TEST(LogarythmicGainInputConverter, convertSample_Oracle0ToMinus40_returnsMatchOracle)
{
	LogarythmicGainInputConverter converter(0.0, -40.0);
	testEverySampleConversion(&converter, oracleStandardInput, oracleLogarythmicGainConverterOutput_0dB_Minus40dB, oracleStandardInputSize);
}


TEST(LogarythmicGainInputConverter, convertBuffer_Oracle0ToMinus40_outputBufferMatchesOracle)
{
	LogarythmicGainInputConverter converter(0.0, -40.0);
	testBufferConversion(&converter, oracleStandardInput, oracleLogarythmicGainConverterOutput_0dB_Minus40dB, oracleStandardInputSize);
}