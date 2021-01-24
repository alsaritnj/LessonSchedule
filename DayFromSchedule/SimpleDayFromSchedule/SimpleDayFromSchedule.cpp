#include "SimpleDayFromSchedule.h"

SimpleDayFromSchedule::SimpleDayFromSchedule(std::initializer_list<LessonInSchedule*> lessonsInSchedule)
{
	this->lessonsInSchedule.reserve(lessonsInSchedule.size());
	for (auto& el : lessonsInSchedule)
	{
		this->lessonsInSchedule.emplace_back(el);
	}
}

SimpleDayFromSchedule::~SimpleDayFromSchedule()
{
	for (const auto& el : lessonsInSchedule)
		delete el;
}

const LessonInSchedule& SimpleDayFromSchedule::operator[](const int& numberOfLessonInSchedule)
{
	std::vector<LessonInSchedule*>::iterator temp = std::find_if(lessonsInSchedule.begin(), lessonsInSchedule.end(),
		[numberOfLessonInSchedule](LessonInSchedule* a)
		{
			return numberOfLessonInSchedule == a->numberInSchedule();
		});
	if (temp == lessonsInSchedule.end())
	{
		throw std::exception("The lesson under the number that was passed does not exist");
	}
	else
		return **temp;
}