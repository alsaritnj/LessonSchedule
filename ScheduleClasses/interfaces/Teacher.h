#pragma once
#include <string>
#include "ClassName.h"

class Teacher : public ClassName
{
public:
	virtual std::string getName() const = 0;
	virtual std::string getSurname() const = 0;
	virtual std::string getPatronymic() const = 0;
	virtual void setName(const std::string& name) = 0;
	virtual void setSurname(const std::string& surnae) = 0;
	virtual void setPatronymic(const std::string& patronymic) = 0;
};