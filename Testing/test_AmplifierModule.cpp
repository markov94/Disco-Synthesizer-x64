#include "CppUTest/TestHarness.h"
#include "stubs/InputStub.h"
#include "TestingResources.h"
#include "test_Module.h"
#include "Patch.h"
#include "Modules/AmplifierModule.h"

TEST_GROUP(AmplifierModule)
{
	void setup() {}
	void teardown() {}
};

TEST(AmplifierModule, process_standardAudioAndGainInputs_amplifierModuleWithLinearGainConverterOutput_0dB_Minus40dB)
{
	InputStub* audioInputStub = new InputStub(oracleStandardInput);
	InputStub* gainInputStub = new InputStub(oracleStandardInput);
	Patch patch;
	AmplifierModule testedModule(&patch, oracleStandardInputSize);
	testedModule.setAudioInput(audioInputStub);
	testedModule.setAudioInputConverter(new StandardAudioInputConverter());
	testedModule.setGainInput(gainInputStub);
	testedModule.setGainInputConverter(new LinearGainInputConverter(0.0f, -40.0f));
	testedModule.setQuality(Module::Quality::FULL);
	testedModule.process();
	testModulesOutput(testedModule.getOutputBuffer(), oracleAmplifierModuleWithLinearGainConverterOutput_0dB_Minus40dB);
}


IGNORE_TEST(AmplifierModule, process_processTwiceWithoutReset_doesntProcessSecondTime)
{

}

IGNORE_TEST(AmplifierModule, n)
{
	FAIL("")
}
