#include "FiveDaySchedule.h"

DayFromSchedule& FiveDaySchedule::operator[](short int numberOfDay) { return *daysFromSchedule[numberOfDay - 1]; }

void FiveDaySchedule::addDay(DayFromSchedule* added, const unsigned& numberOfDay)
{
	throwException(numberOfDay > 5, "The number of the day is too big");
	throwException(numberOfDay <= 0, "The number of the day is too small");
	throwExceptionIfPtrIsNullptr(added);
	daysFromSchedule[numberOfDay - 1] = added;
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

 void FiveDaySchedule::delTeacher(const unsigned& index)
 {
	 delete teachers[index];
	 teachers.erase(teachers.begin() + index);
 }
 void FiveDaySchedule::delSubject(const unsigned& index)
 {
	 delete subjects[index];
	 subjects.erase(subjects.begin() + index);
 }
 void FiveDaySchedule::delClassroom(const unsigned& index)
 {
	 delete classrooms[index];
	 classrooms.erase(classrooms.begin() + index);
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

std::string FiveDaySchedule::getNameOfDay(int numberOfDay)
{
	return namesOfDays[numberOfDay - 1];
}
int FiveDaySchedule::getCountOfDay()
{
	return 5;
}

std::string FiveDaySchedule::className() const
{
	return "Five day schedule";
}
std::string FiveDaySchedule::classContent() const
{
	std::string result = "Days from schedyle:";
	for (size_t i = 0; i < daysFromSchedule.size(); i++)
	{
		result += "\n\t" + std::to_string(i) + ". " + daysFromSchedule[i]->classContent();
	}
	result += "teachers";
	for (size_t i = 0; i < teachers.size(); i++)
	{
		result += "\n\t" + std::to_string(i) + ". " + teachers[i]->classContent();
	}
	result += "subjects";
	for (size_t i = 0; i < subjects.size(); i++)
	{
		result += "\n\t" + std::to_string(i) + ". " + subjects[i]->classContent();
	}
	result += "classrooms";
	for (size_t i = 0; i < classrooms.size(); i++)
	{
		result += "\n\t" + std::to_string(i) + ". " + classrooms[i]->classContent();
	}

	return result;
}

inline void FiveDaySchedule::throwException(const bool& circumstance, const char* massage)
{
	if (circumstance)
		throw(std::exception(massage));
}

FiveDaySchedule::FiveDaySchedule(const std::string& customClassName)
{
	_customClassName = customClassName;
}
FiveDaySchedule::FiveDaySchedule(const std::initializer_list<DayFromSchedule*>& daysFromSchedule, const std::string& customClassName)
{
	_customClassName = customClassName;
	throwException(daysFromSchedule.size() != 5, "The count of day from schedule, that was transmitted, is don't equal 5");
	for (auto& el : daysFromSchedule)
	{
		throwExceptionIfPtrIsNullptr(el);
		this->daysFromSchedule.emplace_back(el);
	}
}
FiveDaySchedule::~FiveDaySchedule()
{
	delPtrFromVect(teachers);
	delPtrFromVect(subjects);
	delPtrFromVect(classrooms);
	delPtrFromVect(daysFromSchedule);
}