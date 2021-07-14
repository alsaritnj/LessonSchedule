#pragma once
#include <string>
#include "ClassName.h"

class Classroom : public ClassName
{
public:
	virtual std::string getClassroomNumber() const = 0;
};