#include "EmptyTeacher.h"

std::string EmptyTeacher::getName() const
{
	return " ";
}

std::string EmptyTeacher::getSurname() const
{
	return " ";
}

std::string EmptyTeacher::getPatronymic() const
{
	return " ";
}

void EmptyTeacher::setName(const std::string& name){}

void EmptyTeacher::setSurname(const std::string& surnae){}

void EmptyTeacher::setPatronymic(const std::string& patronymic){}
