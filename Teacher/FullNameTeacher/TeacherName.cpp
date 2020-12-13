#include "TeacherName.h"

TeacherName::TeacherName(const std::string& surname, const std::string& name) :
	name{ std::move(name) },
	surname{ std::move(surname) }
{
	if (this->name == "" or this->name == " " or this->surname == "" or this->surname == " ")
		throw std::exception("Name and surname can't be empty");
}
TeacherName::TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	TeacherName(surname, name)
{
	if (patronymic == "" or patronymic == " ")
		throw std::exception("Patronymic can't be empty");
	this->patronymic = std::move(patronymic);
}

TeacherName::TeacherName(const TeacherName& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->patronymic = other.patronymic;
}
TeacherName::TeacherName(TeacherName&& other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->patronymic = other.patronymic;
	other.name = nullptr;
	other.surname = nullptr;
	other.patronymic = nullptr;
}

std::string TeacherName::getName() const { return name; }
std::string TeacherName::getSurname() const { return surname; }
std::string TeacherName::getPatronymic() const { return patronymic == "" ? "" : patronymic; }

std::ostream& operator<<(std::ostream& os, const Teacher& teacherName)
{
	return os << teacherName.getSurname() << " " << teacherName.getName() << " " << teacherName.getPatronymic();
}