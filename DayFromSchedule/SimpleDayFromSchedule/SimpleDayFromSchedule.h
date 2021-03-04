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
	const LessonInSchedule& operator[](const short int& numberOfLessonInSchedule) override;
	void add(LessonInSchedule* added) override;
	void add(LessonInSchedule* added, const unsigned& numberOfLessonInSchedule) override;
	void del(const short int& numberOfLessonInSchedule) override;
	unsigned countOfLessons() const override;

protected:
	std::vector<LessonInSchedule*> lessonsInSchedule{};
};