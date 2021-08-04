#pragma once
#include "DayFromSchedule.h"
#include "ClassName.h"

class Schedule : public ClassName

{
public:
	virtual DayFromSchedule& operator[](short int numberOfDay) = 0;
	virtual void addDay(DayFromSchedule* added, const unsigned& numberOfDay) = 0;
	virtual void addTeacher(Teacher* teacher) = 0;
	virtual void addSubject(Subject* subject) = 0;
	virtual void addClassroom(Classroom* classroom) = 0;

	virtual void delTeacher(const unsigned& index) = 0;
	virtual void delSubject(const unsigned& index) = 0;
	virtual void delClassroom(const unsigned& index) = 0;

	virtual const Teacher& getTeacher(const unsigned& index) const = 0;
	virtual const Subject& getSubject(const unsigned& index) const = 0;
	virtual const Classroom& getClassroom(const unsigned& index) const = 0;

	virtual const size_t countOfTeachers() = 0;
	virtual const size_t countOfSubjects() = 0;
	virtual const size_t countOfClassrooms() = 0;

	virtual std::string getNameOfDay(int numberOfDay) = 0;
	virtual int getCountOfDay() = 0;
};