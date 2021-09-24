#include "SimpleDayFromSchedule.h"

SimpleDayFromSchedule::SimpleDayFromSchedule(const std::string& customClassName)
{
	_customClassName = customClassName;
	/*this->lessonsInSchedule.reserve(lessonsInSchedule.size());
	for (auto& el : lessonsInSchedule)
		this->lessonsInSchedule.emplace_back(el);
	std::sort(this->lessonsInSchedule.begin(), this->lessonsInSchedule.end());*/
}

SimpleDayFromSchedule::~SimpleDayFromSchedule()
{
	for (const auto& el : lessonsInSchedule)
		delete el;
}

LessonInSchedule& SimpleDayFromSchedule::operator[](const unsigned int& numberOfLessonInSchedule)
{
	return *getLessonByNumber(numberOfLessonInSchedule);
}

const LessonInSchedule& SimpleDayFromSchedule::getLessonByIndex(const unsigned int& index) const
{
	return *lessonsInSchedule[index];
}

LessonInSchedule& SimpleDayFromSchedule::getLessonByIndex(const unsigned int& index)
{
	return *lessonsInSchedule[index];
}

const LessonInSchedule& SimpleDayFromSchedule::operator[](const unsigned int& numberOfLessonInSchedule) const
{
	return *getLessonByNumber(numberOfLessonInSchedule);
}

void SimpleDayFromSchedule::add(LessonInSchedule* added)
{
	for (const auto& el : lessonsInSchedule)
		if (el->getNumberInSchedule() == added->getNumberInSchedule())
			throw(std::exception("a lesson with the same number in the schedule as you tried to add already exists"));
	lessonsInSchedule.emplace_back(added);//ну исправь блин
	std::sort(this->lessonsInSchedule.begin(), this->lessonsInSchedule.end());
}

void SimpleDayFromSchedule::del(const unsigned int& numberOfLessonInSchedule)
{
	//Ё……
	//помоему оно не будет работать корректно, так как удал€те элемент по номерму в массиве, а не по номеру в расписании(по полю класса lessoninschedule)
	//но возмножно € ощибаюсь так что проверь потом

	/// upd. да, возможно такое, что иди бл€ тнахуй 
	if (numberOfLessonInSchedule > lessonsInSchedule.size() + 1)
		throw(std::exception("Too large number of the lesson in the schedule"));
	delete lessonsInSchedule[numberOfLessonInSchedule - 1];
	lessonsInSchedule.erase(lessonsInSchedule.begin() + (numberOfLessonInSchedule - 1));
}

unsigned SimpleDayFromSchedule::countOfLessons() const 
{
	return lessonsInSchedule.size(); 
}

std::string SimpleDayFromSchedule::className() const
{
	return "SimpleDayFromSchedule";
}
#include<iostream>
std::string SimpleDayFromSchedule::classContent() const
{
	std::stringstream result;
	for (auto el : lessonsInSchedule)
	{
		result << "\cl_lesson_" << el << ' ';
	}
	result << _customClassName;
	return result.str();
}

LessonInSchedule* SimpleDayFromSchedule::getLessonByNumber(const unsigned int& numberOfLessonInSchedule) const
{
	auto temp = std::find_if(lessonsInSchedule.begin(), lessonsInSchedule.end(),
		[numberOfLessonInSchedule](LessonInSchedule* a)
		{
			return numberOfLessonInSchedule == a->getNumberInSchedule();
		});
	if (temp == lessonsInSchedule.end())
		throw std::exception("the lesson under the number that was passed does not exist");
	else
		return *temp;
}