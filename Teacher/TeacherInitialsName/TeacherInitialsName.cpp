#include "TeacherInitialsName.h"

TeacherInitialsName::TeacherInitialsName(const std::string& surname,const std::string& name) :
	teacherName{surname, name},
	initialsName { name[0], '.' }{}
TeacherInitialsName::TeacherInitialsName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	teacherName{ surname, name, patronymic },
	initialsName{ name[0], '.' },
	initialsPatronymic{ patronymic[0], '.' }{}

TeacherInitialsName::TeacherInitialsName(const TeacherInitialsName& other) :
	teacherName{ other.teacherName },
	initialsName{ other.initialsName },
	initialsPatronymic{ other.initialsPatronymic }{}
TeacherInitialsName::TeacherInitialsName(TeacherInitialsName&& other) :
	teacherName{ std::move(other.teacherName) },
	initialsName{ std::move(other.initialsName) },
	initialsPatronymic{ std::move(other.initialsPatronymic) }{}

TeacherInitialsName::TeacherInitialsName(const TeacherName& teacherName) :
	teacherName{teacherName},
	initialsName{ teacherName.getName() },
	initialsPatronymic{ teacherName.getPatronymic().empty() ? "" : teacherName.getPatronymic() }
{

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
