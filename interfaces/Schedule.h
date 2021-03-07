#pragma once
#include "DayFromSchedule.h"
#include <vector>
#include <initializer_list>
class Schedule
{
public:
	virtual DayFromSchedule& operator[](short int numberOfDay) = 0;
	virtual void addLessonInTheDay(LessonInSchedule* added, const unsigned& numberOfDay) = 0;
	virtual void addTeacher(Teacher* teacher) = 0;
	virtual void addSubject(Subject* subject) = 0;
	virtual void addClassroom(Classroom* classroom) = 0;
	virtual const Teacher& getTeacher(const unsigned& index) const = 0;
	virtual const Subject& getSubject(const unsigned& index) const = 0;
	virtual const Classroom& getClassroom(const unsigned& index) const = 0;
};