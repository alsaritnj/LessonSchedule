#pragma once
#include "../TeacherName/TeacherName.h"

class TeacherInitialsName : Teacher
{
public:
	TeacherInitialsName(const std::string& surname, const std::string& name, const std::string& patronymic, const std::string& customClassName = "");
	TeacherInitialsName(const TeacherInitialsName& other);
	TeacherInitialsName(TeacherInitialsName&& other);
	TeacherInitialsName(const TeacherName& teacherName);
	operator TeacherName();
	std::string getSurname() const override;
	std::string getName() const override;
	std::string getPatronymic() const override;
	void setName(const std::string& name) override;
	void setSurname(const std::string& surname) override;
	void setPatronymic(const std::string& patronymic) override;

	std::string className() const override;
	std::string classContent() const override;
	
protected:
	TeacherName teacherName;
	std::string initialsName{};
	std::string initialsPatronymic{};
};