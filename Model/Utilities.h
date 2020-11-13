#pragma once
class Utilities
{
public:
	static bool isPowerOfTwo(unsigned x)
	{
		return (x != 0) && ((x & (x - 1)) == 0);
	}

};

