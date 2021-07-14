#include "Sch.h"

Sch::Sch() :
	teacher("name", "surname", "patronymic"),
	subject("subjectname", teacher),
	classroom(15),
	lesson(subject, classroom, 1),
	day({&lesson})
{

}

DayFromSchedule& Sch::operator[](short int numberOfDay)
{
	return day;
}

void Sch::addLessonInTheDay(LessonInSchedule* added, const unsigned& numberOfDay)
{
}

void Sch::addTeacher(Teacher* teacher)
{
}

void Sch::addSubject(Subject* subject)
{
}

void Sch::addClassroom(Classroom* classroom)
{
}

const Teacher& Sch::getTeacher(const unsigned& index) const
{
	return teacher;
}

const Subject& Sch::getSubject(const unsigned& index) const
{
	return subject;
}

const Classroom& Sch::getClassroom(const unsigned& index) const
{
	return classroom;
}

const size_t Sch::countOfTeachers()
{
	return 1;
}

const size_t Sch::countOfSubjects()
{
	return 1;
}

const size_t Sch::countOfClassrooms()
{
	return 1;
}

void Sch::delTeacher(const unsigned& index)
{
}

void Sch::delSubject(const unsigned& index)
{
}

void Sch::delClassroom(const unsigned& index)
{
}

std::string Sch::getNameOfDay(int numberOfDay)
{
	return "Monday";
}

int Sch::getCountOfDay()
{
	return 1;
}

std::string Sch::className() const
{
	return "alyo blyat";
}

std::string Sch::classContent() const
{
	return "nu blin da ler";
}
