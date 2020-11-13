#pragma once
#include "Inputs.h"

class InputStub :
    public Input
{
public:
    InputStub(const float* data)
    {
        this->data = data;
    }

    virtual float getValue(unsigned sampleNumber)
    {
        return data[sampleNumber];
    }
    virtual const float* getData()
    {
        return data;
    }

private:
    const float* data;

};

