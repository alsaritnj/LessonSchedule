#pragma once
#include "DayFromSchedule.h"
#include "ClassName.h"

class Schedule : public ClassName

{
public:
	virtual const DayFromSchedule& operator[](const unsigned int& numberOfDay) const = 0;
	virtual DayFromSchedule& operator[](const unsigned int& numberOfDay) = 0;
	virtual void addLessonInTheDay(const int& numberOfDay, LessonInSchedule* lesson) = 0;
	virtual void delLessonFromTheDay(const int& numberOfDay, const int& numberOfLessonInSchedule) = 0;
	virtual int getCountOfDay() = 0;
};