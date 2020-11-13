#pragma once
#include "SettingsMacros.h"
#include "Exceptions.h"

class Module;


class OutputBuffer
{
public:
	OutputBuffer(Module* owner, const unsigned dataSize);
	~OutputBuffer();

	float* getData();
	Module* getOwner();
	unsigned const getDataSize();

private:
	unsigned dataSize;
	float* data;
	Module* owner;

};

