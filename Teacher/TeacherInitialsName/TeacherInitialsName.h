#pragma once
#include "../TeacherName/TeacherName.h"

class TeacherInitialsName : public TeacherName
{
public:
	TeacherInitialsName(const std::string& surname, const std::string& name);
	TeacherInitialsName(const std::string& surname, const std::string& name, const std::string& patronymic);
	TeacherInitialsName(const TeacherInitialsName& other);
	TeacherInitialsName(TeacherInitialsName&& other);
	TeacherInitialsName(const TeacherName& parent);
	//БЫТЬ АККУРАТНЫМ С ЭТИМ КОНСТРУКТОРОМ, изменяет поля name и patronymic на некорректные(инициалы)
	TeacherInitialsName(const Teacher& parent);
	std::string getName() const override;
	std::string getPatronymic() const override;

protected:
	std::string initialsName{};
	std::string initialsPatronymic{};
};