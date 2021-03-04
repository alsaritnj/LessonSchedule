#include "FiveDaySchedule.h"

DayFromSchedule& FiveDaySchedule::operator[](short int numberOfDay) { return *daysFromSchedule[numberOfDay - 1]; }

void FiveDaySchedule::add(DayFromSchedule* added, const unsigned& numberOfDay)
{
	if (numberOfDay > 5)
		throw(std::exception("Too large number of day"));
	daysFromSchedule.emplace(daysFromSchedule.begin() + (numberOfDay - 1), added);
}

FiveDaySchedule::~FiveDaySchedule()
{
	for (auto& el : teachers)
		delete el;
	for (auto& el : subjects)
		delete el;
	for (auto& el : classrooms)
		delete el;
	for (auto& el : daysFromSchedule)
		delete el;
}
