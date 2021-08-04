#pragma once
#include <string>

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

template<typename T>
ClassName** transformArrayOfPtrToArrayOfPtrOnClassName(T** arrayOfPtr, const size_t& size)
{
	/*Returnable value not const becouse we need to relese allocated memory*/
	ClassName** result = new ClassName* [size];
	for (size_t i = 0; i < size; i++)
	{
		result[i] = static_cast<ClassName*>(arrayOfPtr[i]);
	}
	return result;
}