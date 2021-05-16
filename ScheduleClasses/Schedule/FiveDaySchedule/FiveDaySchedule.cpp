#include "FiveDaySchedule.h"

DayFromSchedule& FiveDaySchedule::operator[](short int numberOfDay) { return *daysFromSchedule[numberOfDay - 1]; }

void FiveDaySchedule::addLessonInTheDay(LessonInSchedule* added, const unsigned& numberOfDay)
{
	throwException(numberOfDay > 5, "The number of the day is too big");
	throwException(numberOfDay <= 0, "The number of the day is too small");
	throwExceptionIfPtrIsNullptr(added);
	daysFromSchedule[numberOfDay - 1]->add(added);
}

void FiveDaySchedule::addTeacher(Teacher* teacher)
{
	throwExceptionIfPtrIsNullptr(teacher);
	teachers.emplace_back(teacher);
}

void FiveDaySchedule::addSubject(Subject* subject)
{
	throwExceptionIfPtrIsNullptr(subject);
	subjects.emplace_back(subject);
}

void FiveDaySchedule::addClassroom(Classroom* classroom)
{
	throwExceptionIfPtrIsNullptr(classroom);
	classrooms.emplace_back(classroom);
}

const Teacher& FiveDaySchedule::getTeacher(const unsigned& index) const 
{
	return *teachers.at(index);
}

const Subject& FiveDaySchedule::getSubject(const unsigned& index) const 
{ 
	return *subjects.at(index);
}

const Classroom& FiveDaySchedule::getClassroom(const unsigned& index) const 
{ 
	return *classrooms.at(index);
}

const size_t FiveDaySchedule::countOfTeachers()
{
	return teachers.size();
}

const size_t FiveDaySchedule::countOfSubjects()
{
	return subjects.size();
}

const size_t FiveDaySchedule::countOfClassrooms()
{
	return classrooms.size();
}

void FiveDaySchedule::delTeacher(const unsigned& index)
{
	teachers.erase(teachers.begin() + index);
}

void FiveDaySchedule::delSubject(const unsigned& index)
{
	subjects.erase(subjects.begin() + index);
}

void FiveDaySchedule::delClassroom(const unsigned& index)
{
	classrooms.erase(classrooms.begin() + index);
}

std::string FiveDaySchedule::getNameOfDay(int numberOfDay)
{
	return namesOfDays[numberOfDay - 1];
}

int FiveDaySchedule::getCountOfDay()
{
	return 5;
}

inline void FiveDaySchedule::throwException(const bool& circumstance, const char* massage)
{
	if (circumstance)
		throw(std::exception(massage));
}

FiveDaySchedule::FiveDaySchedule()
{
}

FiveDaySchedule::FiveDaySchedule(const std::initializer_list<DayFromSchedule*>& daysFromSchedule)
{
	throwException(daysFromSchedule.size() != 5, "The count of day from schedule, that was transmitted, is don't equal 5");
	for (auto& el : daysFromSchedule)
	{
		throwExceptionIfPtrIsNullptr(el);
		this->daysFromSchedule.emplace_back(el);
	}
}

FiveDaySchedule::~FiveDaySchedule()
{
	//слишком много одниковой хуйни, сделай отдельный метод
	for (auto& el : teachers)
		delete el;
	for (auto& el : subjects)
		delete el;
	for (auto& el : classrooms)
		delete el;
	for (auto& el : daysFromSchedule)
		delete el;
}
