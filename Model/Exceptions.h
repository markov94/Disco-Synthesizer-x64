#pragma once
#include <stdexcept>
struct NoOwnerException : public std::exception
{
	const char* what() const throw ()
	{
		return "OutputBuffer has no assigned Module object";
	}
};

struct InvalidBufferSizeException : public std::exception
{
	const char* what() const throw ()
	{
		return "Unacceptable data size";
	}
};

struct InvalidQualityException : public std::exception
{
	const char* what() const throw ()
	{
		return "Unacceptable data size";
	}
};
