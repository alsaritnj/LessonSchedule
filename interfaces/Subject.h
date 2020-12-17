#pragma once
#include <string>
#include "Teacher.h"

class Subject
{
public:
	virtual std::string getSubjectName() const = 0;
	virtual const Teacher& getTeacher() const = 0;
};