<<<<<<< HEAD:interfaces/LessonInSchedule.h
#pragma once
#include "Subject.h"
#include "Classroom.h"
#include "Observer.h"
#include "Publisher.h"

class LessonInSchedule : public Observer, Publisher
{
public:
	virtual const Teacher& getTeacher() const = 0;
	virtual std::string getSubjectName() const = 0;
	virtual std::string getClassroomNumber() const = 0;
	virtual short int getNumberInSchedule() const = 0;
	virtual void setTeacher(Teacher& teacher) = 0;
	virtual void setSubjectName(const std::string& subjectName) = 0;
	virtual void setClassroomNumber(Classroom& classroom) = 0;
	virtual void setNumberInSchedule(const short int& numberInSchedule) = 0;

	virtual bool operator>(const LessonInSchedule& other) const = 0;
	virtual bool operator<(const LessonInSchedule& other) const = 0;
	virtual bool operator>=(const LessonInSchedule& other) const = 0;
	virtual bool operator<=(const LessonInSchedule& other) const = 0;
	virtual bool operator==(const LessonInSchedule& other) const = 0;
	virtual bool operator!=(const LessonInSchedule& other) const = 0;

=======
#pragma once
#include "Subject.h"
#include "Classroom.h"


class LessonInSchedule
{
public:
	virtual const Teacher& getTeacher() const = 0;
	virtual std::string getSubjectName() const = 0;
	virtual std::string getClassroomNumber() const = 0;
	virtual short int getNumberInSchedule() const = 0;
	virtual void setTeacher(Teacher& teacher) = 0;
	virtual void setSubjectName(const std::string& subjectName) = 0;
	virtual void setClassroomNumber(Classroom& classroom) = 0;
	virtual void setNumberInSchedule(const short int& numberInSchedule) = 0;

	virtual bool operator>(const LessonInSchedule& other) const = 0;
	virtual bool operator<(const LessonInSchedule& other) const = 0;
	virtual bool operator>=(const LessonInSchedule& other) const = 0;
	virtual bool operator<=(const LessonInSchedule& other) const = 0;
	virtual bool operator==(const LessonInSchedule& other) const = 0;
	virtual bool operator!=(const LessonInSchedule& other) const = 0;

>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/interfaces/LessonInSchedule.h
};