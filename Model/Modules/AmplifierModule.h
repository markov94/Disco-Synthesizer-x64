#pragma once
#include "Module.h"
#include "InputConverters.h"
#include "Patch.h"
#include "Utilities.h"
#include "Exceptions.h"
#include "OutputBuffer.h"
#include "Inputs.h"

class AmplifierModule :
	public Module
{
public:
	AmplifierModule(Patch* patch, unsigned bufferSize);
	~AmplifierModule();
	virtual void process();
	virtual bool validate();
	virtual void placeModuleInSequence();
	virtual void resetProcessedStatus();
	virtual void resetInternalState();

	void setAudioInput(Input* audioInput);
	void setAudioInputConverter(AudioInputConverter* audioInputConverter);
	void setGainInput(Input* gainInput);
	void setGainInputConverter(GainInputConverter* gainInputConverter);
	OutputBuffer* getOutputBuffer();
	void setQuality(Quality quality);
protected:
	Patch* patch;
	OutputBuffer* outputBuffer;
	Input* audioInput;
	Input* gainInput;
	AudioInputConverter* audioInputConverter;
	GainInputConverter* gainInputConverter;
	bool hasBeenProcessedInThisCycle;
	void processPart(unsigned offset);
	void processAllParts();
	unsigned processingPartsSize;
	unsigned processingPartsNumber;
	float* audioInputConvertedData;
};

