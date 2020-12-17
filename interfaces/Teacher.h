#pragma once
#include <string>

class Teacher
{
public:
	virtual std::string getName() const = 0;
	virtual std::string getSurname() const = 0;
	virtual std::string getPatronymic() const = 0;
};