#pragma once
#include "../../interfaces/Schedule.h"
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
class FiveDaySchedule : Schedule
{
public:
	std::vector<Teacher*> teachers;
	std::vector<Subject*> subjects;
	std::vector<Classroom*> classrooms;

	DayFromSchedule& operator[](short int numberOfDay) override;
	void add(DayFromSchedule* added, const unsigned& numberOfDay) override;
	~FiveDaySchedule();

protected:
	std::vector<DayFromSchedule*> daysFromSchedule{5};
	
};