#pragma once
#include "Subject.h"
#include "Classroom.h"


class LessonInSchedule
{
public:
	virtual const Teacher& getTeacher() const = 0;
	virtual std::string getSubjectName() const = 0;
	virtual std::string getClassroomNumber() const = 0;
	virtual short unsigned int getNumberInSchedule() const = 0;
};