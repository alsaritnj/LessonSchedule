#pragma once
#include "LessonInSchedule.h"
#include <vector>
#include "Observer.h"
#include "Publisher.h"

class DayFromSchedule : public  Observer, Publisher
{
public:
	virtual const LessonInSchedule& operator[](const short int& numberOfLessonInSchedule) = 0;
	virtual void add(LessonInSchedule* added) = 0;
	virtual void del(const short int& numberOfLessonInSchedule) = 0;
	virtual unsigned countOfLessons() const = 0;
};