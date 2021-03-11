#pragma once
#include "../../interfaces/Teacher.h"

class EmptyTeacher : public Teacher
{
public:
	std::string getName() const override;
	std::string getSurname() const override;
	std::string getPatronymic() const override;
	void setName(const std::string& name) override;
	void setSurname(const std::string& surnae) override;
	void setPatronymic(const std::string& patronymic) override;
};