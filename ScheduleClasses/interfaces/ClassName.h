#pragma once
#include <string>
#include <typeinfo>
#include <sstream>

#define EscSequenceToClassPtr "&cl"//всегда должно быть 3 символа, а то получишь баг в FileSaverInString, нужно бы исправить

// not really an interface, but it's better than repeating the code and giving care of the _customClassName field to another class

class ClassName
{
public:
	virtual std::string className() const = 0;
	virtual std::string classContent() const = 0;
	virtual std::string customClassName() const { return _customClassName; }
	virtual std::string& customClassName() { return _customClassName; }

protected:
	std::string _customClassName{};
};
