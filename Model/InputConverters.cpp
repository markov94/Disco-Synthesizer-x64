#include "InputConverters.h"
#include <iostream>

float StandardAudioInputConverter::convertSample(float sample)
{
	return sample;
}

void StandardAudioInputConverter::convertBuffer(const float* input, float* output, unsigned numberOfSamples)
{
	arm_copy_f32((float32_t*)input, output, numberOfSamples);
}

float LinearGainInputConverter::convertSample(float sample)
{
	float limitedValue = limitValueToRangeOfSine(sample);
	return calculateFactorFromSample(limitedValue);


}

void LinearGainInputConverter::convertBuffer(const float* input, float* output, unsigned numberOfSamples)
{
	for (unsigned i = 0; i < numberOfSamples; i++)
	{
		output[i] = convertSample(input[i]);
	}


}

float GainInputConverter::limitValueToRangeOfSine(float value)
{
	if (value > 1.0f) return 1.0f;
	if (value < -1.0f) return -1.0f;
	return value;
}

float GainInputConverter::calculateFactorFromDb(float decibels)
{
	return powf(10.0f,decibels*0.05f);
}

float LinearGainInputConverter::calculateFactorFromSample(float sample)
{	
	return minimalFactor + intervalBetweenMinMaxFactors * ((sample + 1.0f) * 0.5f);
}

void LinearGainInputConverter::calculateCurrentMinMaxFactors()
{
	maximalFactor = calculateFactorFromDb(maxGainDb);
	minimalFactor = calculateFactorFromDb(minGainDb);
}

void LinearGainInputConverter::calculateIntervalBetweenMinMaxFactors()
{
	intervalBetweenMinMaxFactors = maximalFactor - minimalFactor;
}

float LogarythmicGainInputConverter::convertSample(float sample)
{
	float sampleLimited = limitValueToRangeOfSine(sample);
	float gainInDecibels = calculateDbFromSample(sampleLimited);
	float gainFactor = calculateFactorFromDb(gainInDecibels);
	return gainFactor;
}

void LogarythmicGainInputConverter::convertBuffer(const float* input, float* output, unsigned numberOfSamples)
{
	for (unsigned i = 0; i < numberOfSamples; i++)
	{
		output[i] = convertSample(input[i]);
	}
}

float LogarythmicGainInputConverter::calculateDbFromSample(float sample)
{

	return minGainDb + minMaxGainDbInterval * ((sample+1.0f)*0.5f);
}

void LogarythmicGainInputConverter::calculateIntervalBetweenMinMaxGainDecibels()
{
	this->minMaxGainDbInterval = this->maxGainDb - this->minGainDb;
}
