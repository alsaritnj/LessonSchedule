#pragma once
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <exception>

class SimpleDayFromSchedule : public DayFromSchedule
{
public:
	SimpleDayFromSchedule(std::initializer_list<LessonInSchedule*> lessonsInSchedule);
	~SimpleDayFromSchedule();
	const LessonInSchedule& operator[](const int& numberOfLessonInSchedule) override;

protected:
	std::vector<LessonInSchedule*> lessonsInSchedule{};
};