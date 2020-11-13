#pragma once
#include "arm_math.h"

class Patch;
class Module
{
public:
	virtual void process() = 0;
	virtual bool validate() = 0;
	virtual void placeModuleInSequence() = 0;
	virtual void resetProcessedStatus() = 0;
	virtual void resetInternalState() = 0;
	virtual ~Module() {}

	enum class Quality
	{
		FULL=1U,
		HIGHER=4U,
		HIGH=8U,
		NORMAL=16U,
		FAST=32U,
		FASTER=64U,
		FASTEST=128U
	};

};

