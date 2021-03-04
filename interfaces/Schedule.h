#pragma once
#include "DayFromSchedule.h"
#include <vector>
#include <initializer_list>
class Schedule
{
public:
	virtual DayFromSchedule& operator[](short int numberOfDay) = 0;
	virtual void add(DayFromSchedule* added, const unsigned& numberOfDay) = 0;
};