#pragma once
#include "arm_math.h"

class InputConverter
{
public:
	virtual float convertSample(float sample) = 0;
	virtual void convertBuffer(const float* input, float* output, unsigned numberOfSamples) = 0;
protected:
	InputConverter() {}
};

class AudioInputConverter : public InputConverter {};


/*
	Pass-thru
*/
class StandardAudioInputConverter : public AudioInputConverter
{
public:
	virtual float convertSample(float sample);
	virtual void convertBuffer(const float* input, float* output, unsigned numberOfSamples);
};

class GainInputConverter : public InputConverter {
public:
	float getMaxGainDb() { return maxGainDb; }
	float getMinGainDb() { return minGainDb; }
	void setMaxGainDb(float maxGainDb) { this->maxGainDb = maxGainDb; }
	void setMinGainDb(float minGainDb) { this->minGainDb = minGainDb; }
protected:
	float maxGainDb, minGainDb;
	GainInputConverter(float maxGainDb, float minGainDb) : maxGainDb(maxGainDb), minGainDb(minGainDb) {}
	float limitValueToRangeOfSine(float value);
	float calculateFactorFromDb(float decibels);
};


class LinearGainInputConverter : public GainInputConverter
{
public:
	LinearGainInputConverter(float maxGainDb, float minGainDb) : GainInputConverter(maxGainDb, minGainDb) {
		calculateCurrentMinMaxFactors();
		calculateIntervalBetweenMinMaxFactors();
	}
	virtual float convertSample(float sample);
	virtual void convertBuffer(const float* input, float* output, unsigned numberOfSamples);
	
protected:
	float maximalFactor, minimalFactor, intervalBetweenMinMaxFactors;
	
	float calculateFactorFromSample(float sample);
	void calculateCurrentMinMaxFactors();
	void calculateIntervalBetweenMinMaxFactors();
};

class LogarythmicGainInputConverter : public GainInputConverter
{
public:
	LogarythmicGainInputConverter(float maxGainDb, float minGainDb) : GainInputConverter(maxGainDb, minGainDb) {
		calculateIntervalBetweenMinMaxGainDecibels();
	}
	virtual float convertSample(float sample);
	virtual void convertBuffer(const float* input, float* output, unsigned numberOfSamples);
protected:
	float calculateDbFromSample(float sample);
	float minMaxGainDbInterval;
	void calculateIntervalBetweenMinMaxGainDecibels();
};