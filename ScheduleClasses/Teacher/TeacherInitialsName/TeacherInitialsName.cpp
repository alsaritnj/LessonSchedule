#include "TeacherInitialsName.h"

TeacherInitialsName::TeacherInitialsName(const std::string& surname,const std::string& name, const std::string& patronymic, const std::string& customClassName) :
	teacherName{surname, name, patronymic, customClassName},
	initialsName { name[0], '.' },
	initialsPatronymic{patronymic[0], '.'}
{
	_customClassName = customClassName;
}

TeacherInitialsName::TeacherInitialsName(const TeacherInitialsName& other) :
	teacherName{ other.teacherName },
	initialsName{ other.initialsName },
	initialsPatronymic{ other.initialsPatronymic }
{
	_customClassName = other._customClassName;
}
TeacherInitialsName::TeacherInitialsName(TeacherInitialsName&& other) :
	teacherName{ std::move(other.teacherName) },
	initialsName{ std::move(other.initialsName) },
	initialsPatronymic{ std::move(other.initialsPatronymic) }
{
	_customClassName = std::move(other._customClassName);
}

TeacherInitialsName::TeacherInitialsName(const TeacherName& teacherName) :
	teacherName{teacherName},
	initialsName{ teacherName.getName()[0] },
	initialsPatronymic{ teacherName.getPatronymic()[0] }
{
	_customClassName = teacherName.customClassName();
}
TeacherInitialsName::operator TeacherName() { return teacherName; }

std::string TeacherInitialsName::getSurname() const { return teacherName.getSurname(); }
std::string TeacherInitialsName::getName() const { return initialsName; }
std::string TeacherInitialsName::getPatronymic() const { return initialsPatronymic; }

void TeacherInitialsName::setName(const std::string& name)
{
	this->teacherName.setName(name);
	this->initialsName = name[0] + '.';
}

void TeacherInitialsName::setSurname(const std::string& surname)
{
	this->teacherName.setSurname(surname);
}

void TeacherInitialsName::setPatronymic(const std::string& patronymic)
{
	this->teacherName.setPatronymic(patronymic);
	this->initialsName = patronymic[0] + '.';
}

std::string TeacherInitialsName::className() const
{
	return "TeacherInitialsName";
}

std::string TeacherInitialsName::classContent() const
{
	return teacherName.classContent();
}
