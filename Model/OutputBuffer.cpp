#include "OutputBuffer.h"
#include "Utilities.h"
#include <stdexcept>

OutputBuffer::OutputBuffer(Module* owner, const unsigned dataSize) : owner(owner) {
	if (!Utilities::isPowerOfTwo(dataSize)) throw std::runtime_error("Errno 1");
	this->dataSize = dataSize;
	data = new float[dataSize];

}

OutputBuffer::~OutputBuffer() {
	delete[] data;
}

float* OutputBuffer::getData() 
{ 
	return data; 
}

Module* OutputBuffer::getOwner()
{
	if (owner == nullptr)
		throw std::runtime_error("Errno 1");
	return owner;
}

unsigned const OutputBuffer::getDataSize()
{
	return dataSize;
}
