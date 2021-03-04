#pragma once
#include "LessonInSchedule.h"
#include <vector>

class DayFromSchedule
{
public:
	virtual const LessonInSchedule& operator[](const short int& numberOfLessonInSchedule) = 0;
	virtual void add(LessonInSchedule* added) = 0;
	virtual void add(LessonInSchedule* added, const unsigned& numberOfLessonInSchedule) = 0;
	virtual void del(const short int& numberOfLessonInSchedule) = 0;
	virtual unsigned countOfLessons() const = 0;
};