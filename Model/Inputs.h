#pragma once

class Input
{
public:
	virtual float getValue(unsigned sampleNumber) = 0;
	virtual const float* getData() = 0;
};