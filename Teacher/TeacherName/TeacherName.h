#pragma once
#include "../../interfaces/Teacher.h"
#include <string>
#include <exception>
#include <ostream>

class TeacherName : public Teacher
{
public:
	TeacherName(const std::string& surname, const std::string& name);
	TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic);
	TeacherName(const TeacherName& other);
	TeacherName(TeacherName&& other);
	std::string getName() const override;
	std::string getSurname() const override;
	std::string getPatronymic() const override;

protected:
	std::string name{};
	std::string surname{};
	std::string patronymic{};
};

std::ostream& operator<<(std::ostream& os, const Teacher& teacherName);