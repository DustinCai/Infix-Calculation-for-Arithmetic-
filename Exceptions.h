#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class StackIsEmpty : public std::runtime_error
{
private:

public:
	StackIsEmpty(std::string errMsg) : runtime_error(errMsg)
	{
	}
};

class QueueIsEmpty : public std::runtime_error
{
private:

public:
	QueueIsEmpty(std::string errMsg) : runtime_error(errMsg)
	{
	}
};


#endif