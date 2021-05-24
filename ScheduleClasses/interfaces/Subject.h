<<<<<<< HEAD:interfaces/Subject.h
#pragma once
#include <string>
#include "Teacher.h"
#include "Observer.h"
#include "Publisher.h"

class Subject : public Observer, Publisher
{
public:
	virtual std::string getSubjectName() const = 0;
	virtual const Teacher& getTeacher() const = 0;
	virtual void setSubjectName(const std::string& subjectName) = 0;
	virtual void setTeacher(Teacher& teacher) = 0;
=======
#pragma once
#include <string>
#include "Teacher.h"

class Subject
{
public:
	virtual std::string getSubjectName() const = 0;
	virtual const Teacher& getTeacher() const = 0;
	virtual void setSubjectName(const std::string& subjectName) = 0;
	virtual void setTeacher(Teacher& teacher) = 0;
>>>>>>> 689b03797aa664e15f462a7efeaeb85cdb6340d9:ScheduleClasses/interfaces/Subject.h
};