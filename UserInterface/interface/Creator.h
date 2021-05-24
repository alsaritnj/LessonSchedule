#pragma once
#include <string>
//methods name is realy broke in this interface, I now this bud I don't now how to name this right.
class Creator
{
public:
	virtual void* create() = 0;
	virtual std::string getAsk(const int& index) = 0;
	virtual void setParameter(const int& index, void* parameter) = 0;
	virtual int getCountOfParameters() = 0;
	virtual std::string asString() = 0;
};