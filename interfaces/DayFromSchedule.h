#pragma once
#include "LessonInSchedule.h"

class DayFromSchedule
{
public:
	virtual const LessonInSchedule& operator[](const int& numberOfLessonInSchedule) = 0;
};