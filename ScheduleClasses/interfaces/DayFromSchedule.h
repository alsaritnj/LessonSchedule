#pragma once
#include "LessonInSchedule.h"
#include "ClassName.h"

class DayFromSchedule : public ClassName
{
public:
	virtual const LessonInSchedule& operator[](const unsigned int& numberOfLessonInSchedule) const = 0;
	virtual LessonInSchedule& operator[](const unsigned int& numberOfLessonInSchedule) = 0;
	virtual const LessonInSchedule& getLessonByIndex(const unsigned int& index) const = 0;
	virtual LessonInSchedule& getLessonByIndex(const unsigned int& index) = 0;
	virtual void add(LessonInSchedule* added) = 0;
	virtual void del(const unsigned int& numberOfLessonInSchedule) = 0;
	virtual unsigned countOfLessons() const = 0;
};