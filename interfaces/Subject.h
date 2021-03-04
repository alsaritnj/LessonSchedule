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
};