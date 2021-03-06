#include "SimpleDayFromSchedule.h"

SimpleDayFromSchedule::SimpleDayFromSchedule(std::initializer_list<LessonInSchedule*> lessonsInSchedule)
{
	this->lessonsInSchedule.reserve(lessonsInSchedule.size());
	for (auto& el : lessonsInSchedule)
		this->lessonsInSchedule.emplace_back(el);
	std::sort(this->lessonsInSchedule.begin(), this->lessonsInSchedule.end());
}

SimpleDayFromSchedule::~SimpleDayFromSchedule()
{
	for (const auto& el : lessonsInSchedule)
		delete el;
}

const LessonInSchedule& SimpleDayFromSchedule::operator[](const short int& numberOfLessonInSchedule)
{
	std::vector<LessonInSchedule*>::iterator temp = std::find_if(lessonsInSchedule.begin(), lessonsInSchedule.end(),
		[numberOfLessonInSchedule](LessonInSchedule* a)
		{
			return numberOfLessonInSchedule == a->getNumberInSchedule();
		});
	if (temp == lessonsInSchedule.end())
			throw std::exception("The lesson under the number that was passed does not exist");
	else 
		return **temp;
}

void SimpleDayFromSchedule::add(LessonInSchedule* added)
{
	add(added, lessonsInSchedule.size() + 1);
}

void SimpleDayFromSchedule::add(LessonInSchedule* added, const unsigned& numberOfLessonInSchedule)
{
	if (numberOfLessonInSchedule > lessonsInSchedule.size() + 1)
		throw(std::exception("too large number of the lesson in the schedule"));
	lessonsInSchedule.emplace(lessonsInSchedule.begin() + (numberOfLessonInSchedule - 1), added);
}

void SimpleDayFromSchedule::del(const short int& numberOfLessonInSchedule)
{
	if (numberOfLessonInSchedule > lessonsInSchedule.size() + 1)
		throw(std::exception("too large number of the lesson in the schedule"));
	delete lessonsInSchedule[numberOfLessonInSchedule - 1];
	lessonsInSchedule.erase(lessonsInSchedule.begin() + (numberOfLessonInSchedule - 1));
}

unsigned SimpleDayFromSchedule::countOfLessons() const
{
	return lessonsInSchedule.size();
}
