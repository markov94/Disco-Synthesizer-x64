#include "CppUTest/TestHarness.h"
#include "OutputBuffer.h"
#include "SettingsMacros.h"

TEST_GROUP(OutputBuffer)
{
	void setup() {}
	void teardown() {}
};

TEST(OutputBuffer, getOwner_hasNullOwner_throwsException)
{
	OutputBuffer outputBuffer(nullptr, SYNTH_BUFFER_SIZE);
	CHECK_THROWS(std::runtime_error, outputBuffer.getOwner());
}

TEST(OutputBuffer, getOwner_hasOwner_returnOwner)
{
	int* ModulePointerFake = new int;
	OutputBuffer outputBuffer((Module*)ModulePointerFake, SYNTH_BUFFER_SIZE);
	CHECK_EQUAL((Module*)ModulePointerFake,outputBuffer.getOwner());
	delete ModulePointerFake;
}

TEST(OutputBuffer, constructedWithBadDataSize_throwsException)
{
	int* fakeModulePointer = new int;
	CHECK_THROWS(std::runtime_error, OutputBuffer((Module*)fakeModulePointer, 0));
	CHECK_THROWS(std::runtime_error, OutputBuffer((Module*)fakeModulePointer, 3));
	CHECK_THROWS(std::runtime_error, OutputBuffer((Module*)fakeModulePointer, 5));
	CHECK_THROWS(std::runtime_error, OutputBuffer((Module*)fakeModulePointer, 0));
	delete fakeModulePointer;
}
