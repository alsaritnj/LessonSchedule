#pragma once
#include <string>
#include <vector>
#include "../../ScheduleClasses/interfaces/Teacher.h"
#include "../../ScheduleClasses/interfaces/Classroom.h"
#include "../../ScheduleClasses/interfaces/Subject.h"
#include "../../ScheduleClasses/interfaces/Schedule.h"

class FileOpener
{
public:
	virtual void open(const std::string&) = 0;
	virtual Schedule* getSchedule() = 0;
	virtual std::vector<Classroom*> getClassrooms() = 0;
	virtual	std::vector<Teacher*> getTeachers() = 0;
	virtual	std::vector<Subject*> getSubjects() = 0;
};