#include "FiveDaySchedule.h"

FiveDaySchedule::FiveDaySchedule(const std::string& customClassName)
{
	_customClassName = customClassName;
}

FiveDaySchedule::~FiveDaySchedule()
{
	for (const auto& el : days)
		delete el;
}

const DayFromSchedule& FiveDaySchedule::operator[](const unsigned int& numberOfDay) const
{
	return *days[numberOfDay - 1];
}

DayFromSchedule& FiveDaySchedule::operator[](const unsigned int& numberOfDay)
{
	return *days[numberOfDay - 1];
}

void FiveDaySchedule::addLessonInTheDay(const int& numberOfDay, LessonInSchedule* lesson)
{
	days[numberOfDay - 1]->add(lesson);
}

void FiveDaySchedule::delLessonFromTheDay(const int& numberOfDay, const int& numberOfLessonInSchedule)
{
	days[numberOfDay - 1]->del(numberOfLessonInSchedule);
}

int FiveDaySchedule::getCountOfDay()
{
	return 5;
}

std::string FiveDaySchedule::className() const
{
	return "FiveDaySchedule";
}

std::string FiveDaySchedule::classContent() const
{
	return "NE HOCHU";
}
