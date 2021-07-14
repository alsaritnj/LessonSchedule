 #include "SimpleSubject.h"
#include <iostream>
SimpleSubject::SimpleSubject(const std::string& subjectName, Teacher& teacher, const std::string& customClassName) :
	teacher{&teacher},
	subjectName{subjectName}
{
	_customClassName = customClassName;
}

SimpleSubject::SimpleSubject(const SimpleSubject& other) :
	teacher{other.teacher},
	subjectName{ other.subjectName }
{
	_customClassName = other._customClassName;
}
SimpleSubject::SimpleSubject(SimpleSubject&& other) :
	teacher{other.teacher},
	subjectName{other.subjectName}
{
	_customClassName = std::move(other._customClassName);
}

std::string SimpleSubject::getSubjectName() const { return subjectName; }
const Teacher& SimpleSubject::getTeacher() const { return *teacher; }

void SimpleSubject::setSubjectName(const std::string& subjectName) { this->subjectName = subjectName; }

void SimpleSubject::setTeacher(Teacher& teacher) { this->teacher = &teacher; }

std::string SimpleSubject::className() const
{
	return "Simple subject";
}

std::string SimpleSubject::classContent() const
{
	return "Subject name " + subjectName + " teacher " + teacher->classContent();
}