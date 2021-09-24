#include "TeacherName.h"

TeacherName::TeacherName(const std::string& surname, const std::string& name, const std::string& patronymic, const std::string& customClassName) :
	name{ name },
	surname{ surname },
	patronymic{ patronymic }
{
	_customClassName = customClassName;
}

TeacherName::TeacherName(const TeacherName& other) :
	name{other.name},
	surname{other.surname},
	patronymic{other.patronymic}
{}

TeacherName::TeacherName(TeacherName&& other) :
	name{ std::move(other.name) },
	surname{ std::move(other.surname) },
	patronymic{ std::move(other.patronymic) }
{}

std::string TeacherName::getName() const { return name; }
std::string TeacherName::getSurname() const { return surname; }
std::string TeacherName::getPatronymic() const { return patronymic; }

void TeacherName::setName(const std::string& name)
{
	if (name.empty())
		throw(std::exception("Name can't be empty"));
	this->name = name;
}

void TeacherName::setSurname(const std::string& surname)
{
	if (name.empty())
		throw(std::exception("Purname can't be empty"));
	this->surname;
}

void TeacherName::setPatronymic(const std::string& patronymic)
{
	if (name.empty())
		throw(std::exception("Patronymic can't be empty"));
	this->patronymic = patronymic;
}

std::string TeacherName::className() const
{
	return "TeacherName";
}

std::string TeacherName::classContent() const
{
	return name + ' ' + surname + ' ' + patronymic + ' ' + _customClassName;
}


std::ostream& operator<<(std::ostream& os, const Teacher& teacherName)
{
	return os << teacherName.getSurname() << " " << teacherName.getName() << " " << teacherName.getPatronymic();
}