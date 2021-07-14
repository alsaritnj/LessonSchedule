#include "SimpleClassroom.h"
#include <iostream>

SimpleClassroom::SimpleClassroom(const std::string& classroomNumber, const std::string& customClassName) :
	classroomNumber{classroomNumber}
{
	_customClassName = customClassName;
}

SimpleClassroom::SimpleClassroom(const int& classroomNumber, const std::string& customClassName) :
	classroomNumber{std::to_string(classroomNumber), customClassName }
{
}

SimpleClassroom::SimpleClassroom(const SimpleClassroom & other):
	classroomNumber( other.classroomNumber )
{
	_customClassName = other._customClassName;
}

SimpleClassroom::SimpleClassroom(SimpleClassroom&& other):
	classroomNumber(std::move(other.classroomNumber))
{
	_customClassName = std::move(other._customClassName);
}

std::string SimpleClassroom::getClassroomNumber() const
{
	return classroomNumber;
}

std::string SimpleClassroom::className() const
{
	return "Simple classroom";
}

std::string SimpleClassroom::classContent() const
{
	return "Classroom \"" + classroomNumber + "\"";
}
=======
std::string SimpleClassroom::getClassroomNumber() const { return classroomNumber; }