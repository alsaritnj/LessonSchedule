#pragma once
#include "Subject.h"
#include "Classroom.h"
#include "ClassName.h"


class LessonInSchedule : public ClassName
{
public:
	virtual const Teacher& getTeacher() const = 0;
	virtual std::string getSubjectName() const = 0;
	virtual std::string getClassroomNumber() const = 0;
	virtual short int getNumberInSchedule() const = 0;
	virtual void setSubject(Subject& subjectName) = 0;
	virtual void setClassroom(Classroom& classroom) = 0;
	virtual void setNumberInSchedule(const short int& numberInSchedule) = 0;

	virtual bool operator>(const LessonInSchedule& other) const = 0;
	virtual bool operator<(const LessonInSchedule& other) const = 0;
	virtual bool operator>=(const LessonInSchedule& other) const = 0;
	virtual bool operator<=(const LessonInSchedule& other) const = 0;
	virtual bool operator==(const LessonInSchedule& other) const = 0;
	virtual bool operator!=(const LessonInSchedule& other) const = 0;
};