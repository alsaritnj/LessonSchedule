#include "SimpleSubject.h"

SimpleSubject::SimpleSubject(const std::string& subjectName, Teacher& teacher) :
	teacher{teacher},
	subjectName{subjectName}
{}

SimpleSubject::SimpleSubject(const SimpleSubject& other) :
	teacher(other.teacher),
	subjectName(other.subjectName)
{}
SimpleSubject::SimpleSubject(SimpleSubject&& other) :
	teacher(other.teacher),
	subjectName(other.subjectName)
{}

std::string SimpleSubject::getSubjectName() const
{
	return subjectName;
}
const Teacher& SimpleSubject::getTeacher() const
{
	return teacher;
}
