#include "AmplifierModule.h"

AmplifierModule::AmplifierModule(Patch* patch, unsigned bufferSize)
{
	if (!Utilities::isPowerOfTwo(bufferSize)) throw InvalidBufferSizeException();
	outputBuffer = new OutputBuffer(this, bufferSize);

	this->patch = patch;
	audioInput = nullptr;
	audioInputConverter = nullptr;
	gainInput = nullptr;
	gainInputConverter = nullptr;
	audioInputConvertedData = nullptr;
	hasBeenProcessedInThisCycle = false;

	unsigned dataSize = outputBuffer->getDataSize();
	audioInputConvertedData = new float[dataSize];

	setQuality(Quality::NORMAL);
}

AmplifierModule::~AmplifierModule()
{
	if(outputBuffer != nullptr) delete outputBuffer;
	if (audioInput != nullptr) delete audioInput;
	if (audioInputConverter != nullptr) delete audioInputConverter;
	if (gainInput != nullptr) delete gainInput;
	if (gainInputConverter != nullptr) delete gainInputConverter;
	if (audioInputConvertedData != nullptr) delete[] audioInputConvertedData;
}

void AmplifierModule::process()
{
	if (hasBeenProcessedInThisCycle) return;
	hasBeenProcessedInThisCycle = true;
	processAllParts();
}

bool AmplifierModule::validate()
{
	return false;
}

void AmplifierModule::placeModuleInSequence()
{
}

void AmplifierModule::resetProcessedStatus()
{
	hasBeenProcessedInThisCycle = false;
}

void AmplifierModule::resetInternalState()
{
}

void AmplifierModule::setAudioInput(Input* audioInput)
{
	this->audioInput = audioInput;
}

void AmplifierModule::setAudioInputConverter(AudioInputConverter* audioInputConverter)
{
	this->audioInputConverter = audioInputConverter;
}

void AmplifierModule::setGainInput(Input* gainInput)
{
	this->gainInput = gainInput;
}

void AmplifierModule::setGainInputConverter(GainInputConverter* gainInputConverter)
{
	this->gainInputConverter = gainInputConverter;
}

OutputBuffer* AmplifierModule::getOutputBuffer()
{
	return outputBuffer;
}

void AmplifierModule::setQuality(Quality quality)
{
	unsigned processingPartsSize = (unsigned)quality;
	if (!Utilities::isPowerOfTwo(processingPartsSize)) throw InvalidQualityException();
	if(processingPartsSize < 1) throw InvalidQualityException();
	if (processingPartsSize > outputBuffer->getDataSize()) throw InvalidQualityException();

	this->processingPartsSize = processingPartsSize;
	this->processingPartsNumber = outputBuffer->getDataSize() / processingPartsSize;
}

void AmplifierModule::processAllParts()
{
	audioInputConverter->convertBuffer(audioInput->getData(), audioInputConvertedData, outputBuffer->getDataSize());
	for (unsigned currentPart = 0; currentPart < processingPartsNumber; currentPart++)
	{
		uint32_t offset = currentPart * processingPartsSize;
		processPart(offset);
	}
}

void AmplifierModule::processPart(unsigned offset)
{
	float gain = gainInputConverter->convertSample(gainInput->getValue(offset));
	arm_scale_f32(audioInputConvertedData+offset, gain, outputBuffer->getData() + offset, processingPartsSize);

}