#pragma once
#include "../../interfaces/DayFromSchedule.h"
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <exception>

class SimpleDayFromSchedule : public DayFromSchedule
{
public:
	SimpleDayFromSchedule(std::initializer_list<const LessonInSchedule*> lessonsInSchedule, const std::string& customClassName = "");
	~SimpleDayFromSchedule();
	const LessonInSchedule& operator[](const unsigned int& numberOfLessonInSchedule) override;
	void add(const LessonInSchedule& added) override;
	void del(const unsigned int& numberOfLessonInSchedule) override;
	unsigned countOfLessons() const override;

	std::string className() const override;
	std::string classContent() const override;

protected:
	std::vector<LessonInSchedule*> lessonsInSchedule{};
};