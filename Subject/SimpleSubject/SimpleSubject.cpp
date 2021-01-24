#include "SimpleSubject.h"
                                                           //heare added "const"
SimpleSubject::SimpleSubject(const std::string& subjectName, const Teacher& teacher) :
	teacher{teacher},
	subjectName{subjectName}
	//я хз почему Teacher& принимался неконстантным, но все равно заменил на константный
	//не уверен, что это не сломает что-то
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
