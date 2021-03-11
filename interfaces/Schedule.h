#pragma once
#include "DayFromSchedule.h"
#include <vector>
#include <initializer_list>
#include "Observer.h"
#include "Publisher.h"

class Schedule : public Observer, Publisher
{
public:
	virtual DayFromSchedule& operator[](short int numberOfDay) = 0;
	virtual void addDay(DayFromSchedule* added, const unsigned& numberOfDay) = 0;
	virtual void addTeacher(Teacher* teacher) = 0;
	virtual void addSubject(Subject* subject) = 0;
	virtual void addClassroom(Classroom* classroom) = 0;
	virtual Teacher& getTeacher(const unsigned& index) = 0;
	virtual Subject& getSubject(const unsigned& index) = 0;
	virtual Classroom& getClassroom(const unsigned& index) = 0;
	virtual void delTeacher(const unsigned& index) = 0;
	virtual void delSubject(const unsigned& index) = 0;
	virtual void delClassroom(const unsigned& index) = 0;
};