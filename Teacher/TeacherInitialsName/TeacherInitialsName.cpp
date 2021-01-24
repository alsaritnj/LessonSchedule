#include "TeacherInitialsName.h"

TeacherInitialsName::TeacherInitialsName(const std::string& surname,const std::string& name) :
	teacherName{surname, name},
	initialsName { name[0], '.' }{}
TeacherInitialsName::TeacherInitialsName(const std::string& surname, const std::string& name, const std::string& patronymic) :
	teacherName{ surname, name, patronymic },
	initialsName{ name[0], '.' },
	initialsPatronymic{ patronymic[0], '.' }
{}

TeacherInitialsName::TeacherInitialsName(const TeacherInitialsName& other) :
	teacherName{ other.teacherName },
	initialsName{ other.initialsName },
	initialsPatronymic{ other.initialsPatronymic }{}
TeacherInitialsName::TeacherInitialsName(TeacherInitialsName&& other) :
	teacherName{ std::move(other.teacherName) },
	initialsName{ std::move(other.initialsName) },
	initialsPatronymic{ std::move(other.initialsPatronymic) }{}

std::string TeacherInitialsName::getSurname() const { return teacherName.getSurname(); }
std::string TeacherInitialsName::getName() const { return initialsName; }
std::string TeacherInitialsName::getPatronymic() const { return initialsPatronymic; }
