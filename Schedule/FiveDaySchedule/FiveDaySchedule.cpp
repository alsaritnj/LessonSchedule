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

Teacher& FiveDaySchedule::getTeacher(const unsigned& index) { return *teachers.at(index); }

Subject& FiveDaySchedule::getSubject(const unsigned& index) { return *subjects.at(index); }

 Classroom& FiveDaySchedule::getClassroom(const unsigned& index) { return *classrooms.at(index); }

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

inline void FiveDaySchedule::throwException(const bool& circumstance, const char* massage)
{
	if (circumstance)
		throw(std::exception(massage));
}

FiveDaySchedule::~FiveDaySchedule()
{
	delPtrFromVect(teachers);
	delPtrFromVect(subjects);
	delPtrFromVect(classrooms);
	delPtrFromVect(daysFromSchedule);
}
