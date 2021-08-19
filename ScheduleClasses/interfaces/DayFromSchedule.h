#pragma once
#include "LessonInSchedule.h"
#include "ClassName.h"

class DayFromSchedule : public ClassName
{
public:
	virtual const LessonInSchedule& operator[](const unsigned int& numberOfLessonInSchedule) = 0;
	virtual void add(const LessonInSchedule& added) = 0;
	virtual void del(const unsigned int& numberOfLessonInSchedule) = 0;
	virtual unsigned countOfLessons() const = 0;
};