#include "SimpleSubject.h"

SimpleSubject::SimpleSubject(const std::string& subjectName, Teacher& teacher) :
	teacher{teacher},
	subjectName{subjectName}
{}

std::string SimpleSubject::getSubjectName() const
{
	return subjectName;
}

const Teacher& SimpleSubject::getTeacher() const
{
	return teacher;
}
