#pragma once
#include "../FullNameTeacher/TeacherName.h"

class TeacherInitialsName : public TeacherName
{
public:
	TeacherInitialsName(const std::string& surname, const std::string& name);
	TeacherInitialsName(const std::string& surname, const std::string& name, const std::string& patronymic);
	TeacherInitialsName(const TeacherName& parent);
	TeacherInitialsName(TeacherName&& parent);
	std::string getName() const override;
	std::string getPatronymic() const override;

protected:
	std::string initialsName{};
	std::string initialsPatronymic{};
};