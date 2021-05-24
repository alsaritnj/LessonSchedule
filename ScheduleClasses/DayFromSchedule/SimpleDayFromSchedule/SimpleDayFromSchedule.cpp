<<<<<<< HEAD:DayFromSchedule/SimpleDayFromSchedule/SimpleDayFromSchedule.cpp
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
	for (const auto& el : lessonsInSchedule)
		if (el->getNumberInSchedule() == added->getNumberInSchedule())
			throw(std::exception("a lesson with the same number in the schedule as you tried to add already exists"));
	lessonsInSchedule.emplace_back(added);
	std::sort(this->lessonsInSchedule.begin(), this->lessonsInSchedule.end());
}

void SimpleDayFromSchedule::del(const short int& numberOfLessonInSchedule)
{
	if (numberOfLessonInSchedule > lessonsInSchedule.size() + 1)
		throw(std::exception("Too large number of the lesson in the schedule"));
	delete lessonsInSchedule[numberOfLessonInSchedule - 1];
	lessonsInSchedule.erase(lessonsInSchedule.begin() + (numberOfLessonInSchedule - 1));
}

unsigned SimpleDayFromSchedule::countOfLessons() const { return lessonsInSchedule.size(); }

void SimpleDayFromSchedule::notifySubscribers() const { publisher.notifySubscribers(); }

void SimpleDayFromSchedule::subscribe(const Observer* observer) { publisher.subscribe(observer); }

void SimpleDayFromSchedule::unsubscribe(const Observer* observer) { publisher.unsubscribe(observer); }

void SimpleDayFromSchedule::notify() const
{
}
=======
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
	for (const auto& el : lessonsInSchedule)
		if (el->getNumberInSchedule() == added->getNumberInSchedule())
			throw(std::exception("a lesson with the same number in the schedule as you tried to add already exists"));
	lessonsInSchedule.emplace_back(added);
	std::sort(this->lessonsInSchedule.begin(), this->lessonsInSchedule.end());
}

void SimpleDayFromSchedule::del(const short int& numberOfLessonInSchedule)
{
	if (numberOfLessonInSchedule > lessonsInSchedule.size() + 1)
		throw(std::exception("Too large number of the lesson in the schedule"));
	delete lessonsInSchedule[numberOfLessonInSchedule - 1];
	lessonsInSchedule.erase(lessonsInSchedule.begin() + (numberOfLessonInSchedule - 1));
}

unsigned SimpleDayFromSchedule::countOfLessons() const { return lessonsInSchedule.size(); }
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/DayFromSchedule/SimpleDayFromSchedule/SimpleDayFromSchedule.cpp
