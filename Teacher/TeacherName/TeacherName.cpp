#include "TeacherName.h"

TeacherName::TeacherName(const std::string& surname, const std::string& name) :
	name{ name },
	surname{ surname }
{
	if (this->name == "" or this->name == " " or this->surname == "" or this->surname == " ")
		throw std::exception("Name and surname can't be empty");
}
TeacherName::TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	TeacherName{ surname, name }
{
	if (patronymic == "" or patronymic == " ")
		throw std::exception("Patronymic can't be empty");
	this->patronymic = { patronymic };
}

TeacherName::TeacherName(const TeacherName& other) :
	name{other.name},
	surname{other.surname},
	patronymic{other.patronymic}{}
TeacherName::TeacherName(TeacherName&& other) :
	name{ std::move(other.name) },
	surname{ std::move(other.surname) },
	patronymic{ std::move(other.patronymic) }{}


std::string TeacherName::getName() const { return name; }
std::string TeacherName::getSurname() const { return surname; }
std::string TeacherName::getPatronymic() const { return patronymic; }

std::ostream& operator<<(std::ostream& os, const Teacher& teacherName)
{
	return os << teacherName.getSurname() << " " << teacherName.getName() << " " << teacherName.getPatronymic();
}