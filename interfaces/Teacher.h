#pragma once
#include <string>

class Teacher
{
public:
	virtual std::string getName() const = 0;
	virtual std::string getSurname() const = 0;
	virtual std::string getPatronymic() const = 0;
	virtual void setName(const std::string& name) = 0;
	virtual void setSurname(const std::string& surnae) = 0;
	virtual void setPatronymic(const std::string& patronymic) = 0;
};