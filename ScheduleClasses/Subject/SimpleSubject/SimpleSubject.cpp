<<<<<<< HEAD:Subject/SimpleSubject/SimpleSubject.cpp
 #include "SimpleSubject.h"
#include <iostream>
SimpleSubject::SimpleSubject(const std::string& subjectName, Teacher& teacher) :
	teacher{&teacher},
	subjectName{subjectName}{}

SimpleSubject::SimpleSubject(const SimpleSubject& other) :
	teacher{other.teacher},
	subjectName{ other.subjectName }{}
SimpleSubject::SimpleSubject(SimpleSubject&& other) :
	teacher{other.teacher},
	subjectName{other.subjectName}{}

std::string SimpleSubject::getSubjectName() const { return subjectName; }
const Teacher& SimpleSubject::getTeacher() const { return *teacher; }

void SimpleSubject::setSubjectName(const std::string& subjectName) { this->subjectName = subjectName; }

void SimpleSubject::setTeacher(Teacher& teacher) 
{ 
	delete this->teacher;
	this->teacher = &teacher; 
}


=======
 #include "SimpleSubject.h"
#include <iostream>
SimpleSubject::SimpleSubject(const std::string& subjectName, Teacher& teacher) :
	teacher{&teacher},
	subjectName{subjectName}{}

SimpleSubject::SimpleSubject(const SimpleSubject& other) :
	teacher{other.teacher},
	subjectName{ other.subjectName }{}
SimpleSubject::SimpleSubject(SimpleSubject&& other) :
	teacher{other.teacher},
	subjectName{other.subjectName}{}

std::string SimpleSubject::getSubjectName() const { return subjectName; }
const Teacher& SimpleSubject::getTeacher() const { return *teacher; }

void SimpleSubject::setSubjectName(const std::string& subjectName) { this->subjectName = subjectName; }

void SimpleSubject::setTeacher(Teacher& teacher) { this->teacher = &teacher; }


>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/Subject/SimpleSubject/SimpleSubject.cpp