#include "TeacherInitialsName.h"
#include <iostream>

TeacherInitialsName::TeacherInitialsName(const std::string& surname,const std::string& name) :
	TeacherName{surname, name}
{
	initialsName = { this->name[0], '.' };
}
TeacherInitialsName::TeacherInitialsName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	TeacherName(surname, name, patronymic)
{	
	initialsName = { this->name[0], '.' };
	initialsPatronymic = { this->patronymic[0], '.' };
}

TeacherInitialsName::TeacherInitialsName(const TeacherName& parent) :
	TeacherName(parent)
{
	this->initialsName = { name[0], '.' };
	this->initialsPatronymic = { patronymic[0], '.' };
}
TeacherInitialsName::TeacherInitialsName(TeacherName&& parent) :
	TeacherName(parent)
{
	this->initialsName = { name[0], '.' };
	this->initialsPatronymic = { patronymic[0], '.' };
}

std::string TeacherInitialsName::getName() const { return initialsName; }
std::string TeacherInitialsName::getPatronymic() const { return patronymic == "" ? "" : initialsPatronymic; }
